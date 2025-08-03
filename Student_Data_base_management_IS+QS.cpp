#include <iostream>
#include <string>
using namespace std;

class student {
private:
    string name;
    int roll_no;
    float cgpa;

public:
    void setter() {
        cout << "Enter the name of student: ";
        cin.ignore();              
        getline(cin, name);       

        cout << "Enter Roll no. in digits of student: ";
        cin >> roll_no;

        cout << "Enter CGPA attained by the student in past year: ";
        cin >> cgpa;
    }

    void getter() const {
        cout << "Name of student: " << name << endl;
        cout << "Roll no. of student: " << roll_no << endl;
        cout << "CGPA Attained: " << cgpa << endl;
    }

    int getRollNo() const {
        return roll_no;
    }
};

void insertion_sort(student s[], int n) {
    for (int i = 1; i < n; i++) {
        student key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j].getRollNo() > key.getRollNo()) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

void quick_sort(student s[], int f, int l) {
    if (f < l) {
        int pvt = f;
        int i = f + 1;
        int j = l;
        student temp;

        while (i <= j) {
            while (i <= l && s[i].getRollNo() <= s[pvt].getRollNo()) {
                i++;
            }

            while (j >= f + 1 && s[j].getRollNo() > s[pvt].getRollNo()) {
                j--;
            }

            if (i < j) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }

        temp = s[pvt];
        s[pvt] = s[j];
        s[j] = temp;

        quick_sort(s, f, j - 1);
        quick_sort(s, j + 1, l);
    }
}


int main() {
    const int n = 3;
    student s[n];
    
    char ch;
    int a; 
    
while(1)
{
cout<<"Enter do you want to Proceed in Y/N:";
cin>>ch;

if(ch=='Y' || ch=='y') {
cout<<"Menu: 1:Input the data\n2:Output the data\n3:Insertion sort\n4:Quick sort\n Enter your choice:";
cin>>a;

switch(a)
{
case 1:
    for (int i = 0; i < n; i++) {
        s[i].setter();
        cout << endl;
    }
break;
  
case 2:
    cout << "Sorted student details by Roll No:\n";
    for (int i = 0; i < n; i++) {
        s[i].getter();
        cout << endl;
    }
break;

case 3:
    insertion_sort(s, n);
    cout << "Sorted student details by Roll No:\n";
    for(int i = 0; i < n; i++) {
        s[i].getter();
        cout << endl;
    }
break;
     
case 4:
     quick_sort(s,0,2);
    cout << "Sorted student details by Roll No:\n";
    for (int i = 0; i < n; i++) {
        s[i].getter();
        cout << endl;
    }
break;

default:
cout<<"Enter a valid menu no.";
break;
}
}
else {break;}
}
    return 0;
}

