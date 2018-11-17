#include <iostream>
using namespace std;
struct seatinfo
{
    char row;
    int no;
    int avail;
    int cost;
    int id;
    struct seatinfo *next;
};
typedef struct seatinfo *node;


node getnode()
{
    node temp;
    temp=(node)malloc(sizeof(struct seatinfo));
    temp->next=NULL;
    temp->avail=1;
    return temp;
}
string moviename[3];
void movname(string name,int p)
    {
        moviename[0]="Movie 1";
        moviename[1]="Movie 2";
        moviename[2]="Movie 3";
        moviename[p]=name;
    }

class admin
{

    int platinum,gold,silver;
    public:
    int earning=0;




    void admindisplay()
    {
        cout<<"Earning : "<<earning;
    }

};
class seat:public admin
{
    public:
    int platinum,gold,silver,p=3,g=5,s=2;
       node head=NULL;
        node last=NULL;
    seat()
    {

        platinum=200;
        gold=150;
        silver=100;
    }

    void mseat()
    {
    for(int i=0;i<(p+g+s);i++)
    for(int j=0;j<10;j++)
    {
        if(head==NULL)
        {
            node temp=getnode();
            temp->row='A';
            temp->no=1;
            temp->cost=200;
            temp->id=(temp->row * temp->no * temp->cost)/7;
            last=temp;
            head=temp;
        }
        else
        {
            node temp=getnode();
            temp->row=65+i;
            temp->no=j+1;
            if(i<=2)
                temp->cost=platinum;
            else if(i>2 && i<8)
                temp->cost=gold;
            else
                temp->cost=silver;
            temp->id=(temp->row * temp->no * temp->cost)/7;
            last->next=temp;
            last=temp;
        }
    }


    }
};

class display:public seat
{
public:
   void sdisplay(int z)
   {
    node temp=head;
    cout<<"\n\n          MOVIE : "<<moviename[z];
    cout<<"\n****************PLATINUM*************\n\n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(temp->avail)
                cout<<"  "<<temp->row<<temp->no;
            else
                cout<<"    ";
            temp=temp->next;

        }
        cout<<endl;
    }
       cout<<"\n*****************GOLD*******************\n\n";
    for(int i=0;i<g;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(temp->avail)
                cout<<"  "<<temp->row<<temp->no;
            else
                cout<<"    ";
            temp=temp->next;
        }
        cout<<endl;
    }

       cout<<"\n**********SILVER************\n\n";
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<10;j++)
        {
           if(temp->avail)
                cout<<"  "<<temp->row<<temp->no;
            else
                cout<<"    ";
            temp=temp->next;

        }
        cout<<endl;
    }
    }

};

class customer:public display
{
    public:
    void sbook()
    {
        char choice1;
        int choice2,i,j,flag=1;
        cout<<"Enter row\n";
        cin>>choice1;
        cout<<"Enter seat number\n";
        cin>>choice2;

        node temp=head;
        for(int i=0;i<(p+g+s);i++)
        { if(!flag)
                break;
        for(int j=0;j<10;j++)
        {
            if(choice1==temp->row && choice2==temp->no)
            {
                if(temp->avail)
               {
                    cout<<"Your Booking is confirmed \nCost : "<<temp->cost<<"\nBooking Id : "<<temp->id;
                    earning+=temp->cost;
                    temp->avail=0;
                }
                else
                    cout<<"The Seat is already booked!\n";
                    flag=0;
                    break;
            }

            temp=temp->next;
        }
        }
    }

    void scancel()
    {
        node temp=head;
        int choiceid;
        cout<<"Enter booking ID : ";
        cin>>choiceid;

        while(temp && choiceid!=temp->id )
            temp=temp->next;

        if(temp)
        {
                temp->avail=1;
                cout<<"Booking Cancelled \nAmount Refunded : "<<temp->cost;
                earning-=temp->cost;
        }
        else
            cout<<"Wrong Booking Id\n";
    }
};

using namespace std;

int main()
{
    customer o1[3];
    int choice;
    string pass="0000";
    cout<<"Enter 1 : Admin   2 : Customer : ";
    cin>>choice;
    if(choice==1)
        {
            string p;
            cout<<"Enter the Password : ";
            cin>>p;
            if(p==pass)
            {
                int c;
                cout<<"\n1:Insert Movie  2:Ticket Transaction : ";
                cin>>c;
                if(c==1){
                int screen;
                string name;
                cout<<"Enter Screen No : ";
                cin>>screen;
                cout<<"Enter movie name : ";
                cin>>name;
                movname(name,screen-1);
            }
            }}

    for(int i=0;i<2;i++){
    o1[i].mseat();
    o1[i].sdisplay(i);
    o1[i].sbook();
    o1[i].sdisplay(i);
    o1[i].scancel();
    o1[i].admindisplay();
    }
    return 0;
}
