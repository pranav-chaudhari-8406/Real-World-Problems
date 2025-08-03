#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Retailer
{
private:
    string p_name;
    float p_price;

public:
    void getter()
    {
        cout << "Product Name: " << p_name << endl;
        cout << "Product Price: " << p_price << endl;
    }

    float ret_price() { return p_price; }

    void setter()
    {
        cout << "Enter the Product name: ";
        cin >> p_name;
        cout << "Enter the Product price: ";
        cin >> p_price;
    }
};

void sort_product(Retailer product[], int f, int l) {
    if (f < l) {
        int pvt = f;
        int i = f + 1;
        int j = l;
        Retailer temp;

        while (i <= j) {
            while (i <= l && product[i].ret_price() <= product[pvt].ret_price()) {
                i++;
            }

            while (j >= f + 1 && product[j].ret_price() > product[pvt].ret_price()) {
                j--;
            }

            if (i < j) {
                temp = product[i];
                product[i] = product[j];
                product[j] = temp;
            }
        }

        temp = product[pvt];
        product[pvt] = product[j];
        product[j] = temp;

        sort_product(product, f, j - 1);
        sort_product(product, j + 1, l);
    }
}

int main()
{
    int n;

    cout << "Enter the number of products to be entered: ";
    cin >> n;

    Retailer* product = new Retailer[n];  // Dynamic array to avoid VLA issues

    char ch;
    int x;

    while (true)
    {
        cout << "Do you want to proceed? (Y/N): ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            cout << "MENU - Enter the option number:\n";
            cout << "1) Input product details\n";
            cout << "2) Output product details\n";
            cout << "3) Sort products by price\n";
            cin >> x;

            switch (x)
            {
            case 1:
                for (int i = 0; i < n; i++)
                {
                    product[i].setter();
                    cout << endl;
                }
                break;

            case 2:
                cout << "Product details:\n";
                for (int i = 0; i < n; i++)
                {
                    product[i].getter();
                    cout << endl;
                }
                break;

            case 3:
                sort_product(product, 0, n - 1);
                cout << "Products sorted by price:\n";
                for (int i = 0; i < n; i++)
                {
                    product[i].getter();
                    cout << endl;
                }
                break;

            default:
                cout << "Enter a valid menu number.\n";
                break;
            }
        }
        else
            break;
    }

    delete[] product;  // Free allocated memory

    return 0;
}

