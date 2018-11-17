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
node head1=NULL;
node last1=NULL;
node head2=NULL;
node last2=NULL;
node head3=NULL;
node last3=NULL;

node getnode()
{
    node temp;
    temp=(node)malloc(sizeof(struct seatinfo));
    temp->next=NULL;
    temp->avail=1;
    return temp;
}

class seat
{
    public:
    int platinum,gold,silver,p=3,g=5,s=2;
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
        if(head1==NULL)
        {
            node temp=getnode();
            temp->row='A';
            temp->no=1;
            temp->cost=200;
            temp->id=(temp->row * temp->no * temp->cost)/7;
            last1=temp;
            head1=temp;
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
            last1->next=temp;
            last1=temp;
        }
    }
    cout<<head1->cost;

    }
};

class display:public seat
{
public:
   void sdisplay(node head,node last)
   {
    node temp=head;
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
    void sbook(node head,node last)
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

    void scancel(node head,node last)
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
        }
        else
            cout<<"Wrong Booking Id\n";
    }
};

using namespace std;

int main()
{

    customer o1;
    o1.mseat();
    o1.sdisplay(head1,last1);
    o1.sbook(head1,last1);
    o1.sdisplay(head1,last1);
    o1.scancel(head1,last1);
    o1.sdisplay(head1,last1);
    return 0;
}
