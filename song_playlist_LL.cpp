#include<bits/stdc++.h>
using namespace std;

class node{                              //creating nodes
    public:
      string sname;
      node* next;
 
    node(){
        sname="Empty";
        next=NULL;
    }
 
    node(string s) {
        sname=s;
        next=NULL;
    }

};

class song_playlist{                      //creating links for nodes
public:
     node* head;
     
     song_playlist(){head=NULL;}
     
void insert_end(string s){
     node* newnode= new node(s);           //parameterized const call

     if(head==NULL)  head=newnode;
     else{
        node *T=head;
        while(T->next!=NULL)
        {
            T=T->next;
        }
            T->next= newnode;
     }
}


void insert_beg(string s){
    node*newnode = new node(s);            //parameterized const call

     if(head==NULL)
    { head = newnode;}
     else{
        newnode->next=head;
    }
    head=newnode;
}

void insert_pos(string s, int pos) {
    node* newnode = new node(s);

    if (pos <= 1 || head == NULL) {
        insert_beg(s);
        return;
    }

    node* temp = head;
    int count = 1;

    while (temp->next != NULL && count < pos - 1) {           //traverse untill pos-1
        temp = temp->next;
        count++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void print(){
    if(head==NULL) {
        cout<<"Empty\n";
        return;
    }
   
    node* T = head;
    while(T != NULL) {
        cout << T->sname <<endl;
        T = T->next;
    }
    cout << endl;
}


};


int main(){
   song_playlist s;
   
    char ch;    //for yes or no
    int x;      //for choice
    
    while(1)
    {
        cout << "Do you want to proceed??\nPlease Enter Y/N:\n";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            cout << "MENU:Enter the value to proceed:\n1)Insert song at end\n2)Insert song at beg\n3)Insert song at position\n4)Display songs playlist\n";
            cin >> x;
            switch (x)
            {
            case 1:
                s.insert_end("Saiyara");
                cout<<"--------------------------------\n";
                break;

            case 2:
               s.insert_beg("Aashiqui");
               cout<<"--------------------------------\n";
                break;

            case 3:
                 s.insert_pos("Gym Phonk",2);
                  cout<<"--------------------------------\n";
                break;

            case 4:
            cout<<"Your Music Playlist is:"<<endl;
                s.print();
                 cout<<"--------------------------------\n";
                break;

            default:
                cout << "Enter a valid menu no.\n";
                 cout<<"--------------------------------\n";
                break;
            }
            }
        else
            break;
    }
    
return 0;
}



