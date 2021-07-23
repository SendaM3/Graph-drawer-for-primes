#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

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

int main()
{
    //Declare window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Graph drawer");

    //Declare variables
    unsigned long long int numerLineExtended{ 0 };
    unsigned long long int numofPrimes      { 0 };
    vector<unsigned long long int> primes;

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
    int first        {  0};
    int second       {  1};
    double primeGaps {  0};
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
           
            if (firstDone == false)
            {
                while (true)
                {
                    if (IsPrime(numerLineExtended))
                    {
                        numofPrimes++;
                        primes.push_back(numerLineExtended);
                    };

                    if (numofPrimes > 9)
                    {
                        break;
                    };
                    numerLineExtended++;
                };

                for (unsigned int i = 0; i < (primes.size() -1); i++)
                {
                    primeGaps += (primes[second] - primes[first]);
                    first += 1;
                    second += 1;
                };
                averageGap = (primeGaps / 10);
                cout << endl << "Average prime gap between 0 and 10: " << averageGap;
                cout << endl << "Amount of numbers to find 10 primes: " << numerLineExtended;
                point1.move(((averageGap * step) + 140), ypos);
                ypos -= 80;
            };
            firstDone = true;
            numofPrimes = 0; 
            first = 0;
            second = 1;

            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.display();
            
            if (secondDone == false)
            {

                while (true)
                {
                    if (IsPrime(numerLineExtended))
                    {
                        numofPrimes++;
                        primes.push_back(numerLineExtended);
                    };

                    if (numofPrimes > 99)
                    {
                        break;
                    };
                    numerLineExtended++;
                };
       
                for (unsigned int i = 0; i < (primes.size() - 1); i++)
                {
                    primeGaps += (primes[second] - primes[first]);
                    first += 1;
                    second += 1;
                };
                averageGap = 0;
                averageGap = (primeGaps / 100);
                cout << endl << "Average prime gap between 0 and 100: " << averageGap;
                cout << endl << "Amount of numbers to find 100 primes: " << numerLineExtended;
                point2.move(((averageGap * step) + 140), ypos);
                ypos -= 70;
            };
            secondDone = true;
            numofPrimes = 0;
            first = 0;
            second = 1;
           
            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.draw(point2);
            window.display();
            
            if (thirdDone == false)
            {

                while (true)
                {
                    if (IsPrime(numerLineExtended))
                    {
                        numofPrimes++;
                        primes.push_back(numerLineExtended);
                    };

                    if (numofPrimes > 999)
                    {
                        break;
                    };
                    numerLineExtended++;
                };

                for (unsigned int i = 0; i < (primes.size() - 1); i++)
                {
                    primeGaps += (primes[second] - primes[first]);
                    first += 1;
                    second += 1;
                };
                averageGap = 0;
                averageGap = (primeGaps / 1000);
                cout << endl << "Average prime gap between 0 and 1000: " << averageGap;
                cout << endl << "Amount of numbers to find 1000 primes: " << numerLineExtended;
                point3.move(((averageGap * step) + 140), ypos);
                ypos -= 70;
            };
            thirdDone = true;
            numofPrimes = 0;
            first = 0;
            second = 1;
            
            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.draw(point2);
            window.draw(point3);
            window.display();

            if (fourthDone == false)
            {

                while (true)
                {
                    if (IsPrime(numerLineExtended))
                    {
                        numofPrimes++;
                        primes.push_back(numerLineExtended);
                    };

                    if (numofPrimes > 9999)
                    {
                        break;
                    };
                    numerLineExtended++;
                };
              
                for (unsigned int i = 0; i < (primes.size() - 1); i++)
                {
                    primeGaps += (primes[second] - primes[first]);
                    first += 1;
                    second += 1;
                };
                averageGap = 0;
                averageGap = (primeGaps / 10000);
                cout << endl << "Average prime gap between 0 and 10,000: " << averageGap;
                cout << endl << "Amount of numbers to find 10,000 primes: " << numerLineExtended;
                point4.move(((averageGap * step) + 140), ypos);
                ypos -= 70;
            };
            fourthDone = true;
            numofPrimes = 0; 
            first = 0;
            second = 1;

            window.display();
            window.clear();
            window.draw(graphSprite);
            window.draw(algorithmSprite);
            window.draw(point1);
            window.draw(point2);
            window.draw(point3);
            window.draw(point4);
            window.display();

            if (fifthDone == false)
            {

                while (true)
                {
                    if (IsPrime(numerLineExtended))
                    {
                        numofPrimes++;
                        primes.push_back(numerLineExtended);
                    };

                    if (numofPrimes > 99999)
                    {
                        break;
                    };
                    numerLineExtended++;
                };
            
                for (unsigned int i = 0; i < (primes.size() - 1); i++)
                {
                    primeGaps += (primes[second] - primes[first]);
                    first += 1;
                    second += 1;
                };
                averageGap = 0;
                averageGap = (primeGaps / 100000);
                cout << endl << "Average prime gap between 0 and 100,000: " << averageGap;
                cout << endl << "Amount of numbers to find 100,000 primes: " << numerLineExtended;
                point5.move(((averageGap * step) + 140), ypos);
                ypos -= 90;
            };
            fifthDone = true;
            numofPrimes = 0;
            first = 0;
            second = 1;

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

            if (sixthDone == false)
            {

                while (true)
                {
                    if (IsPrime(numerLineExtended))
                    {
                        numofPrimes++;
                        primes.push_back(numerLineExtended);
                    };

                    if (numofPrimes > 999999)
                    {
                        break;
                    };
                    numerLineExtended++;
                };
        
                for (unsigned int i = 0; i < (primes.size() - 1); i++)
                {
                    primeGaps += (primes[second] - primes[first]);
                    first += 1;
                    second += 1;
                };
                averageGap = 0;
                averageGap = (primeGaps / 1000000);
                cout << endl << "Average prime gap between 0 and 1,000,000: " << averageGap;
                cout << endl << "Amount of numbers to find 1,000,000 primes: " << numerLineExtended;
                point6.move(((averageGap * step) + 140), ypos);
                ypos -= 70;
            };
            sixthDone = true;
            numofPrimes = 0;
            first = 0;
            second = 1;
          
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
            
            if (seventhDone == false)
            {
               
                while (true)
                {
                    if (IsPrime(numerLineExtended))
                    {
                        numofPrimes++;
                        primes.push_back(numerLineExtended);
                    };

                    if (numofPrimes > 9999999)
                    {
                        break;
                    };
                    numerLineExtended++;
                };
               
                for (unsigned int i = 0; i < (primes.size() - 1); i++)
                {
                    primeGaps += (primes[second] - primes[first]);
                    first += 1;
                    second += 1;
                };
                
                averageGap = 0;
                averageGap = (primeGaps / 10000000);
                cout << endl << "Average prime gap between 0 and 10,000,000: " << averageGap;
                cout << endl << "Amount of numbers to find 10,000,000 primes: " << numerLineExtended;
                point7.move(((averageGap * step) + 140), ypos);
                ypos -= 70;
            };
            
            seventhDone = true;
            numofPrimes = 0;
            first = 0;
            second = 1;

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

            if (eightDone == false)
            {

                while (true)
                {
                    if (IsPrime(numerLineExtended))
                    {
                        numofPrimes++;
                        primes.push_back(numerLineExtended);
                    };

                    if (numofPrimes > 99999999)
                    {
                        break;
                    };
                    numerLineExtended++;
                };

                for (unsigned int i = 0; i < (primes.size() - 1); i++)
                {
                    primeGaps += (primes[second] - primes[first]);
                    first += 1;
                    second += 1;
                };

                averageGap = 0;
                averageGap = (primeGaps / 100000000);
                cout << endl << "Average prime gap between 0 and 100,000,000: " << averageGap;
                cout << endl << "Amount of numbers to find 100,000,000 primes: " << numerLineExtended;
                point8.move(((averageGap * step) + 140), ypos);
                ypos -= 70;
            };

            eightDone = true;
            numofPrimes = 0;
            first = 0;
            second = 1;

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

