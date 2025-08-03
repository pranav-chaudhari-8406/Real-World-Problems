#include <iostream>
#include <string>

using namespace std;

class Manufacturing_plant
{
private:
    float t;
    float time;

public:
    void getter()
    {
        cout << t << endl;
        cout << time << endl;
    }

    float ret_temp() { return t; }
    void setter()
    {
        cout << "Enter the temp:" << endl;
        cin >> t;
        cout << "Enter the time at which temp is recorded:" << endl;
        cin >> time;
    }
};

void sort_temp(Manufacturing_plant temperature[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Manufacturing_plant key = temperature[i];
        int j = i - 1;

        while (j >= 0 && temperature[j].ret_temp() > key.ret_temp())
        {
            temperature[j + 1] = temperature[j];
            j--;
        }
        temperature[j + 1] = key;
    }
}

int main()
{
    int n;

    cout << "Enter the no. of temperatures to be entered:";
    cin >> n;

    Manufacturing_plant temperature[n];

    char ch;
    int x;
    while (1)
    {
        cout << "Do you want to proceed??\nPlease Enter Y/N:\n";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            cout << "MENU:Enter the value to proceed:\n1)Inputing the temperature\n2)outputing the temperature\n3)sort temperature of sensors.\n";
            cin >> x;

            switch (x)
            {
            case 1:
                for (int i = 0; i < n; i++)
                {
                    temperature[i].setter();
                    cout << endl;
                }
                break;

            case 2:
                cout << "Temperatures Readings are:\n";
                for (int i = 0; i < n; i++)
                {
                    temperature[i].getter();
                    cout << endl;
                }
                break;

            case 3:
                sort_temp(temperature, n);
                cout << "Sorted Temperatures Readings are:\n";
                for (int i = 0; i < n; i++)
                {
                    temperature[i].getter();
                    cout << endl;
                }
                break;

            default:
                cout << "Enter a valid menu no.\n";
                break;
            }
        }

        else
            break;
    }

    return 0;
}
