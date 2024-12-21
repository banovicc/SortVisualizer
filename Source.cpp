#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

class kvadrat {
public:
    float height;
    RectangleShape kocka;
    Vector2f pozicija;

    kvadrat(float pos, float width);
    void update();
    void draw(RenderWindow& window);
};

void swap(kvadrat& k1, kvadrat& k2);
int partition(vector<kvadrat>& vec, int low, int high, RenderWindow& window, Event& event);
void quickSort(vector<kvadrat>& vec, int low, int high, RenderWindow& window, Event& event);
void bubbleSort(vector<kvadrat>& v, int size, RenderWindow& window, Event& event);

int main() {

    int numel;
    int method;
    cout << "Number of elements:" << endl;
    cin >> numel;

    cout << "Select sorting method" << endl;
    cout << "For Bubblesort press 1\nFor Quicsort press 2\nNum:";
    cin >> method;

    vector<kvadrat> kvadrati;

    float windowidth = 1200;
    float width = windowidth / numel;

    for (int i = 0; i < numel; i++)
    {
        kvadrati.push_back(kvadrat(i * width, width));
    }

    RenderWindow window(VideoMode(1200, 800), "Sorting");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == event.Closed)
                window.close();
        }

        int n = numel;

        switch (method)
        {
        case 1:
            bubbleSort(kvadrati, n, window, event);
            break;
        case 2:
            quickSort(kvadrati, 0, n - 1, window, event);
            break;
        default:
            break;
        }
        method = -1;
    }
    return 0;
}

kvadrat::kvadrat(float pos, float width)
{
    height = rand() % 800;
    pozicija = Vector2f(pos, 800 - height);
    kocka.setSize(Vector2f(width, height));
    kocka.setPosition(pozicija);
}

void kvadrat::update() {
    kocka.setPosition(pozicija);
}

void kvadrat::draw(RenderWindow& window) {
    window.draw(kocka);
}

void swap(kvadrat& k1, kvadrat& k2)
{
    float k11 = k1.height;
    float k22 = k2.height;

    k1.kocka.setSize(Vector2f(k1.kocka.getSize().x, k22));
    k2.kocka.setSize(Vector2f(k2.kocka.getSize().x, k11));

    k1.pozicija = Vector2f(k1.kocka.getPosition().x, 800 - k22);
    k2.pozicija = Vector2f(k2.kocka.getPosition().x, 800 - k11);

    float temp = k1.height;
    k1.height = k2.height;
    k2.height = temp;
}

int partition(vector<kvadrat>& vec, int low, int high, RenderWindow& window, Event& event) {

    int pivot = vec[high].height;

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (vec[j].height <= pivot) {
            i++;
            swap(vec[i], vec[j]);

            while (window.pollEvent(event))
            {
                if (event.type == event.Closed)
                    window.close();
            }

            for (auto& kruzic : vec)
                kruzic.update();

            window.clear();
            for (auto& kruzic : vec)
                kruzic.draw(window);
            window.display();
        }
    }

    swap(vec[i + 1], vec[high]);

    return (i + 1);
}

void quickSort(vector<kvadrat>& vec, int low, int high, RenderWindow& window, Event& event) {

    if (low < high) {

        int pi = partition(vec, low, high, window, event);

        quickSort(vec, low, pi - 1, window, event);
        quickSort(vec, pi + 1, high, window, event);
    }
}

void bubbleSort(vector<kvadrat>& v, int size, RenderWindow& window, Event& event) {
    int n = size;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (v[j].height > v[j + 1].height)
            {
                swap(v[j], v[j + 1]);

                while (window.pollEvent(event))
                {
                    if (event.type == event.Closed)
                        window.close();
                }

                for (auto& kruzic : v)
                    kruzic.update();

                window.clear();
                for (auto& kruzic : v)
                    kruzic.draw(window);
                window.display();
            }
        }
    }
}