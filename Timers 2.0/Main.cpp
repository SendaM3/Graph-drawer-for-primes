#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <string>
#include <iomanip>
#include <thread>
#include <mutex>

using namespace std::chrono;
using namespace std;
std::mutex mtx;
int ypos{ 780 };

string display(std::chrono::nanoseconds ns)
{
    using namespace std;
    using namespace std::chrono;

    typedef duration<int, ratio<86400>> days;

    stringstream ss;
    char fill = ss.fill();
    ss.fill('0');

    auto d = duration_cast<days>(ns);
    ns -= d;
    auto h = duration_cast<hours>(ns);
    ns -= h;
    auto m = duration_cast<minutes>(ns);
    ns -= m;
    auto s = duration_cast<seconds>(ns);
    ns -= s;
    auto ms = duration_cast<milliseconds>(ns);

    ss  << setw(2) << d.count() << "d:"
        << setw(2) << h.count() << "h:"
        << setw(2) << m.count() << "m:"
        << setw(2) << s.count() << "s:"
        << setw(2) << ms.count() << "ms";

    ss.fill(fill);
    return ss.str();
};

bool IsPrime(unsigned long long int n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (unsigned long long int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

double calcPrimes(unsigned long long int targetPrimes, vector<sf::CircleShape>& pointList, int index)
{
    vector<unsigned long long int> primes;
    int first = 0;
    int second = 1; 
    double primeGaps = 0;
    unsigned long long int numberLineExtended = 0;
    unsigned long long int numofPrimes = 0;
    double averageGap = 0;
    auto startTime = high_resolution_clock::now();
    int step = 80;
    int ypos = 780;

    while (true)
    {
        if (IsPrime(numberLineExtended))
        {
            numofPrimes++;
            primes.push_back(numberLineExtended);
        };

        if (numofPrimes > (targetPrimes-1))
        {
            break;
        };
        numberLineExtended++;
    };

    for (unsigned int i = 0; i < (primes.size() - 1); i++)
    {
        primeGaps += (primes[second] - primes[first]);
        first += 1;
        second += 1;
    };
    mtx.lock();
    averageGap = (primeGaps / (targetPrimes));
    pointList[index].move(((averageGap * step) + 140), ypos - 80 * index);
    cout << endl << "Average prime gap between 0 and " << (targetPrimes) << ": " << averageGap;
    cout << endl << "Amount of numbers to find "  << (targetPrimes) << " primes: " << numberLineExtended << endl;
    auto stopTime = high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<nanoseconds>(stopTime - startTime);
    std::cout << "Operation took: " << display(std::chrono::nanoseconds(duration)) << endl;
    mtx.unlock();
    return averageGap;
}; 

class comma_numpunct : public std::numpunct<char>
{
protected:
    virtual char do_thousands_sep() const { return ','; }
    virtual std::string do_grouping() const { return "\03"; }
};
int main()
{
    //Declare window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Graph drawer");
    std::locale comma_locale(std::locale(), new comma_numpunct());
    std::cout.imbue(comma_locale);

    // Initiate textures
    sf::Texture graphTexture;
    if (!graphTexture.loadFromFile("graph.png")) {}
    sf::Sprite graphSprite;
    graphSprite.setTexture(graphTexture);
    sf::Texture algorithmTexture;

    if (!algorithmTexture.loadFromFile("algorithm.png")) {}
    sf::Sprite algorithmSprite;
    algorithmSprite.setTexture(algorithmTexture);
    algorithmSprite.setScale(0.4, 0.4);
    algorithmSprite.move(800, 35);

    // Make graph points
    vector<sf::CircleShape> pointList;
    for (size_t i = 0; i < 8; i++)
    {
        sf::CircleShape point(50);
        point.setFillColor(sf::Color(0, 0, 0));
        point.setScale(0.2, 0.2);
        pointList.push_back(point);
    }
    
    int target = 10;
    vector<std::thread> threads;
    for (int i = 0; i <= 7; i++)
    {
        threads.push_back(std::thread(calcPrimes, target, std::ref(pointList), i));
        target = (target * 10);
    }; 

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);

            mtx.lock();
            for (size_t i = 0; i < 8; i++)
            {
                window.draw(pointList[i]);
            };
            mtx.unlock();

            window.display();
        }
    }
    return 0;
}

