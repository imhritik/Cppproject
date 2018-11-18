#include <iostream>
#include <cstring>
using namespace std;
struct seatinfo
{
    char row;
    int no;
    int avail;
    int cost;
    string id;
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
string moviename[3]={"Movie 1","Movie 2","Movie 3"};
void movname(string name,int p)
    {
        moviename[p]=name;
    }

class admin
{


    public:
    int earning,platinum,gold,silver;
        admin()
    {
        earning=0;
        platinum=200;
        gold=150;
        silver=100;
    }

    void adminssetprice(int p,int g,int s)
    {
        platinum=p;
        gold=g;
        silver=s;
    }
};
class seat:public admin
{
    public:
    int p=3,g=5,s=2;
       node head=NULL;
        node last=NULL;


    void mseat(int z)
    {
    for(int i=0;i<(p+g+s);i++)
    for(int j=0;j<10;j++)
    {
        if(head==NULL)
        {
            node temp=getnode();
            temp->row='A';
            temp->no=1;
            temp->cost=platinum;
            int a=(temp->row * temp->no * temp->cost*(z+1))/7;
            temp->id=to_string(a);
            last=temp;
            head=temp;
            char b=z+49;
              temp->id+=b;
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
            int a=(temp->row * temp->no * temp->cost*(z+1))/7;
            temp->id=to_string(a);
            last->next=temp;
            last=temp;
                 char b=z+49;
              temp->id+=b;
        }

    }


    }
      void admindisplay(int z)
    {
        node temp=head;

        while(temp!=NULL)
        {
            if(!temp->avail)
            {
                cout<<"Theater : "<<z+1<<endl<<"Seat  : "<<temp->row<<temp->no<<endl;
            }
            temp=temp->next;
        }
        cout<<"***Earning : "<<earning<<"****"<<endl;
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

    void scancel(string choiceid)
    {
        node temp=head;
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
    int choice=1;
    string pass="0000";
    while(choice)
{
    cout<<"Enter 1 : Admin   2 : Customer :  0 : Exit";
    cin>>choice;
    if(choice==1)
        {
            string p;
            cout<<"Enter the Password : ";
            cin>>p;
            if(p==pass)
            {
                int c;
                cout<<"\n1:Insert Movie  2:Ticket Transaction : 3:Set ticket price ";
                cin>>c;
                if(c==1)
            {
                int screen;
                string name;
                cout<<"Enter Screen No : ";
                cin>>screen;
                cout<<"Enter movie name : ";
                cin>>name;
                movname(name,screen-1);
            }
                else if(c==2)
                    {
                        for(int k=0;k<3;k++)
                            o1[k].admindisplay(k);
                    }

                else if(c==3)
                {
                    int plat,go,silv;
                           cout<<"Enter Platinum price : ";
        cin>>plat;
        cout<<"Enter Gold price : ";
        cin>>go;
        cout<<"Enter Silver price : ";
        cin>>silv;
            for(int k=0;k<3;k++)
                o1[k].adminssetprice(plat,go,silv);

                }
            }

            else
                cout<<"Incorrect Password:(\n";
        }
    else if(choice==2)
    {
         for(int i=0;i<3;i++)
        {
            o1[i].mseat(i);
            cout<<"SCREEN : "<<i+1<<" MOVIE : "<<moviename[i]<<endl;
        }
    int screen,c;
    cout<<"1 : Book a ticket  2: Cancel a ticet : ";
    cin>>c;
    if(c==1)
    {
        cout<<"Enter Screen : ";
        cin>>screen;
        o1[screen-1].sdisplay(screen-1);
        o1[screen-1].sbook();
        o1[screen-1].sdisplay(screen-1);
   }
    else if(c==2)
    {
        string choiceid;
        cout<<"Enter booking ID : ";
        cin>>choiceid;
        char z=choiceid[choiceid.length()-1];
        int a=stoi(&z);
        if(a<4)
        {
            cout<<"THEATER : "<<a<<endl;
            o1[a-1].scancel(choiceid);
        }
        else
            cout<<"Wrong Booking Id\n";
    }

    }
}
    return 0;
}
