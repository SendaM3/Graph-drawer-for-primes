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

using namespace std;
using namespace std::chrono;

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

double calcPrimes( unsigned long long int targetPrimes)
{
    vector<unsigned long long int> primes;
    int first = 0;
    int second = 1; 
    double primeGaps = 0;
    unsigned long long int numberLineExtended = 0;
    unsigned long long int numofPrimes = 0;
    double averageGap = 0;

    while (true)
    {
        if (IsPrime(numberLineExtended))
        {
            numofPrimes++;
            primes.push_back(numberLineExtended);
        };

        if (numofPrimes > targetPrimes)
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
    averageGap = (primeGaps / (targetPrimes+1));
    cout << endl << "Average prime gap between 0 and " << (targetPrimes+1) << ": " << averageGap;
    cout << endl << "Amount of numbers to find "  << (targetPrimes+1) << " primes: " << numberLineExtended << endl;
    return averageGap;
}; 
int main()
{
    //Declare window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Graph drawer");

    //Declare variables
    bool firstDone  { false };
    bool secondDone { false };
    bool thirdDone  { false };
    bool fourthDone { false };
    bool fifthDone  { false };
    bool sixthDone  { false };
    bool seventhDone{ false };
    bool eightDone  { false };

    int ypos         {780}; 
    int step         { 80};
    double averageGap{  0};
  
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
    sf::CircleShape point1(50); 
    point1.setFillColor(sf::Color(0, 0, 0));
    point1.setScale(0.2,0.2);
    sf::CircleShape point2(50);
    point2.setFillColor(sf::Color(0, 0, 0));
    point2.setScale(0.2, 0.2);
    sf::CircleShape point3(50);
    point3.setFillColor(sf::Color(0, 0, 0));
    point3.setScale(0.2, 0.2);
    sf::CircleShape point4(50);
    point4.setFillColor(sf::Color(0, 0, 0));
    point4.setScale(0.2, 0.2);
    sf::CircleShape point5(50);
    point5.setFillColor(sf::Color(0, 0, 0));
    point5.setScale(0.2, 0.2);
    sf::CircleShape point6(50);
    point6.setFillColor(sf::Color(0, 0, 0));
    point6.setScale(0.2, 0.2);
    sf::CircleShape point7(50);
    point7.setFillColor(sf::Color(0, 0, 0));
    point7.setScale(0.2, 0.2);
    sf::CircleShape point8(50);
    point8.setFillColor(sf::Color(0, 0, 0));
    point8.setScale(0.2, 0.2);

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
           
            auto startTime = high_resolution_clock::now();
            if (firstDone == false)
            {
                averageGap = calcPrimes(9);
                point1.move(((averageGap * step) + 140), ypos);
                ypos -= 80;
            };

            firstDone = true;
            auto stopTime = high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<nanoseconds>(stopTime - startTime);
            std::cout << "Operation took: " << display(std::chrono::nanoseconds(duration)) << endl;
  
            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.display();
            
            auto startTime1 = high_resolution_clock::now();
            if (secondDone == false)
            {
                averageGap = calcPrimes(99);
                point2.move(((averageGap * step) + 140), ypos);
                ypos -= 80;
            };
            auto stopTime1 = high_resolution_clock::now();
            auto duration1 = std::chrono::duration_cast<nanoseconds>(stopTime1 - startTime1);
            std::cout << "Operation took: " << display(std::chrono::nanoseconds(duration1)) << endl;

            secondDone = true;
        
            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.draw(point2);
            window.display();
            
            auto startTime2 = high_resolution_clock::now();
            if (thirdDone == false)
            {
                averageGap = calcPrimes(999);
                point3.move(((averageGap * step) + 140), ypos);
                ypos -= 80;
            };

            thirdDone = true;
            auto stopTime2 = high_resolution_clock::now();
            auto duration2 = std::chrono::duration_cast<nanoseconds>(stopTime2 - startTime2);
            std::cout << "Operation took: " << display(std::chrono::nanoseconds(duration2)) << endl;
             
            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.draw(point2);
            window.draw(point3);
            window.display();

            auto startTime3 = high_resolution_clock::now();
            if (fourthDone == false)
            {
                averageGap = calcPrimes(9999);
                point4.move(((averageGap * step) + 140), ypos);
                ypos -= 80;
            };
            fourthDone = true;
            auto stopTime3 = high_resolution_clock::now();
            auto duration3 = std::chrono::duration_cast<nanoseconds>(stopTime3 - startTime3);
            std::cout << "Operation took: " << display(std::chrono::nanoseconds(duration3)) << endl;

            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.draw(point2);
            window.draw(point3);
            window.draw(point4);
            window.display();

            auto startTime4 = high_resolution_clock::now();
            if (fifthDone == false)
            {
                averageGap = calcPrimes(99999);
                point5.move(((averageGap * step) + 140), ypos);
                ypos -= 80;
            };
            fifthDone = true;
            auto stopTime4 = high_resolution_clock::now();
            auto duration4 = std::chrono::duration_cast<nanoseconds>(stopTime4 - startTime4);
            std::cout << "Operation took: " << display(std::chrono::nanoseconds(duration4)) << endl;

            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.draw(point2);
            window.draw(point3);
            window.draw(point4);
            window.draw(point5);
            window.display();


            auto startTime5 = high_resolution_clock::now();
            if (sixthDone == false)
            {
                averageGap = calcPrimes(999999);
                point6.move(((averageGap * step) + 140), ypos);
                ypos -= 80;
            };
            sixthDone = true;

            auto stopTime5 = high_resolution_clock::now();
            auto duration5 = std::chrono::duration_cast<nanoseconds>(stopTime5 - startTime5);
            std::cout << "Operation took: " << display(std::chrono::nanoseconds(duration5)) << endl;
          
            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.draw(point2);
            window.draw(point3);
            window.draw(point4);
            window.draw(point5);
            window.draw(point6);
            window.display();
            
            auto startTime6 = high_resolution_clock::now();
            if (seventhDone == false)
            {
                averageGap = calcPrimes(9999999);
                point7.move(((averageGap * step) + 140), ypos);
                ypos -= 80;
            };
            
            seventhDone = true;
            auto stopTime6 = high_resolution_clock::now();
            auto duration6 = std::chrono::duration_cast<nanoseconds>(stopTime6 - startTime6);
            std::cout << "Operation took: " << display(std::chrono::nanoseconds(duration6)) << endl;

            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.draw(point2);
            window.draw(point3);
            window.draw(point4);
            window.draw(point5);
            window.draw(point6);
            window.draw(point7);
            window.display();

            auto startTime7 = high_resolution_clock::now();
            if (eightDone == false)
            {
                averageGap = calcPrimes(99999999);
                point8.move(((averageGap * step) + 140), ypos);
                ypos -= 80;
            };

            eightDone = true;
            auto stopTime7 = high_resolution_clock::now();
            auto duration7 = std::chrono::duration_cast<nanoseconds>(stopTime7 - startTime7);
            std::cout << "Operation took: " << display(std::chrono::nanoseconds(duration7)) << endl;
  
            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.draw(point2);
            window.draw(point3);
            window.draw(point4);
            window.draw(point5);
            window.draw(point6);
            window.draw(point7);
            window.draw(point8);
            window.display();
        }
    }
    return 0;
}

