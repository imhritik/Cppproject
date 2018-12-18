#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct seatinfo
{
    char row;
    int no;
    int avail;
    int cost;
    int fcost;
    string id;
    struct seatinfo *next;
};
typedef struct seatinfo *node;
int counter=0;

node getnode()
{
    node temp;
    temp=(node)malloc(sizeof(struct seatinfo));
    temp->next=NULL;
    temp->avail=1;
    temp->fcost=0;
    return temp;
}
string moviename[3]={"Movie 1","Movie 2","Movie 3"};
void movname(string name,int p)
    {
        moviename[p]=name;
    }

class admin
{
protected:
          int earning,platinum,gold,silver,fearning=0,fcost=0;;
    public:
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
        cout<<"\n Theater : "<<z+1<<endl;
        while(temp!=NULL)
        {

            if(!temp->avail)
            {
                cout<<" Seat  : "<<temp->row<<temp->no<<endl;
            }
            temp=temp->next;
        }
        cout<<" Earning : "<<earning<<endl;
        cout<<" Food Earning : "<<fearning<<endl;
        }

        void txt(int z){
        if(!counter)
        {
            ofstream myfile;
myfile.open("file.txt");
node temp=head;
         myfile<<"Theater : "<<z+1<<endl;
        while(temp!=NULL)
        {
            if(!temp->avail)
            {
                myfile<<"Seat  : "<<temp->row<<temp->no<<endl;
            }
            temp=temp->next;
        }
        myfile<<"**Earning : "<<earning<<"*"<<endl;
        myfile<<"------------\n";
        myfile.close();
        counter++;}

        else{
        ofstream myfile;
myfile.open("file.txt", std::ios_base::app);
node temp=head;
     myfile<<"Theater : "<<z+1<<endl;
        while(temp!=NULL)
        {

            if(!temp->avail)
            {
              myfile<<"Seat  : "<<temp->row<<temp->no<<endl;
            }
            temp=temp->next;
        }
        myfile<<"**Earning : "<<earning<<"*"<<endl;
        myfile<<"------------\n";
        myfile.close();}

}

   void sdisplay(int z)
   {
    node temp=head;
    cout<<"\n PRICES:\n PLATINUM : "<<platinum<<"\n GOLD : "<<gold<<"\n SILVER  : "<<silver;
    cout<<"\n\n\n          MOVIE : "<<moviename[z]<<endl;
    cout<<"\n*****************PLATINUM*****************\n\n";
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
       cout<<"\n*****************GOLD*****************\n\n";
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

       cout<<"\n*****************SILVER*****************\n\n";
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

class customer:public admin
{
    public:
    void sbook()
    {
        char choice1;
        int choice2,i,j,flag=1;
        cout<<"\n\n Enter row  :  ";
        cin>>choice1;
        while(!(choice1>64&&choice1<76))
            {
               cout<<"Wrong Choice!\n";
                cout<<"\n\n Enter row  :  ";
                cin>>choice1;
            }string t;bool numeric=false;
        	   while(!numeric)
		{

            cout<<"\n Enter seat number  :  ";
		    cin>>t;
		    if(t.find_first_not_of("0123456789.") == string::npos){ choice2=stoi(t);
		             if((choice2>0&&choice2<11))

                break;}

		    cout<<" Wrong Input!\n\n\n";
		}
		 choice2=stoi(t);
         if(!(choice2>0&&choice2<11))
            {cout<<"Wrong Choice!";return;}

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
                    cout<<"\n\n Your Booking is confirmed \n Ticket Cost : "<<temp->cost<<"\n Booking Id : "<<temp->id;
                    if(i<p)
                        earning+=platinum;
                    else if(i>p&&i<g)
                        earning+=gold;
                    else
                        earning+=silver;
                    temp->avail=0;
                    int ch;int innerch,psize,csize,cqty,pqty;fcost=0;
                    cout<<"\n\n Would you like to Buy PopCorn and Cold Drinks? ";
                    cout<<"\n 1 - Yes \n 2 - No \n ";
                    cin>>ch;
                    switch(ch)
                        {
                            case 1:cout<<" Press \n 1 - PopCorn \n 2 - Cold Drinks \n ";
                                   cin>>innerch;
                                switch(innerch)
                                    {
                                        case 1: cout<<"\n Enter the size of PopCorn \n";
                                        cout<<" 1 - Small - Rs 100\n 2 - Medium - Rs 150 \n 3 - Large - Rs 200\n ";
                                        cin>>psize;
                                        cout<<" Enter quantity required \n ";
                                        cin>>pqty;
                                        if(psize==1)
                                            {
                                                int temp=100*pqty;
                                                fcost+=temp;
                                                cout<<"\n PopCorn Order Confirmed\n";
                                            }
                                        else if(psize==2)
                                            {
                                                int temp=150*pqty;
                                                fcost+=temp;
                                                cout<<" PopCorn Order Confirmed\n";
                                            }
                                        else if(psize==3)
                                            {
                                                int temp=200*pqty;
                                                fcost+=temp;
                                                cout<<" PopCorn Order Confirmed\n";
                                            }
                                        else
                                                cout<<" Invalid Entry";
                                                break;
                            case 2:cout<<" Enter the size of the Cold Drink Required\n";
                                   cout<<" 1 - Small - Rs 50\n 2 - Medium - Rs 100 \n 3 - Large - Rs 150\n ";
                       cin>>csize;
                       cout<<" Enter quantity\n ";
                       cin>>cqty;
                       if(csize==1)
                       {
                           int temp=50*cqty;
                           fcost+=temp;
                       }
                       else if(csize==2)
                       {
                           int temp=100*cqty;
                           fcost+=temp;                       }
                       else if(csize==3)
                       {
                           int temp=150*cqty;
                           fcost+=temp;                       }
                       else
                        cout<<"Invalid Entry";
                        break;
                        default:cout<<"Invalid Entry";

           }
}
temp->fcost=fcost;
cout<<" Food Cost = "<<temp->fcost<<endl<<endl;
fearning+=fcost;
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
                cout<<" Booking Cancelled \n Amount Refunded : "<<temp->cost;
                earning-=temp->cost;
        }
        else
            cout<<" Wrong Booking Id\n";
    }
};

using namespace std;


bool isNumeric1(string stringToCheck)
{
  bool numeric = false;

  if(stringToCheck.find_first_not_of("0123456789.") == string::npos)
    numeric = true;

  return numeric;
}

int main()
{
    customer o1[3];
    int choice=1;
    string t,pass="0000";
    while(choice)
{
    cout<<"\n\n Enter "<<endl;
    cout<<" 1 : Admin   2 : Customer :  0 : Exit\n ";
    cin>>t;
       while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n\n\n";
           cout<<" 1 : Admin   2 : Customer :  0 : Exit\n ";
            cin>>t;
        }
         choice=stoi(t);

    if(choice==1)
        {
            string p;
            cout<<" Enter the Password : ";
            cin>>p;
            if(p==pass)
            {
                int c=1;
                while(c){

                cout<<"\n 1:Insert Movie  2:Ticket Transaction : 3:Set ticket price  0: Exit\n ";
                cin>>t;
                   while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n\n\n";
            cout<<"\n 1:Insert Movie  2:Ticket Transaction : 3:Set ticket price 0: Exit\n ";
            cin>>t;
        }
         c=stoi(t);
                if(c==1)
            {
                int screen;
                string name;
                cout<<" Enter Screen No : ";
                cin>>t;
                   while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n\n\n";
            cout<<" Enter Screen No : ";
            cin>>t;
        }
         screen=stoi(t);
                if(screen>0&&screen<4){
                cout<<" Enter movie name : ";fflush(stdin);
                cin>>name;
                movname(name,screen-1);}else cout<<" Enter valid details!\n";
            }
                else if(c==2)
                    {
                        for(int k=0;k<3;k++)
                            o1[k].admindisplay(k);
                            counter=0;
                    }

                else if(c==3)
                {
                    int t1;
                    cout<<" Enter Screen : ";
                    cin>>t;
                       while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n\n\n";
            cout<<" Enter Screen : ";
            cin>>t;
        }
         t1=stoi(t);
                    if(t1>0&&t1<4){
                    int plat,go,silv;
                           cout<<" Enter Platinum price : ";
                           cin>>t;
                              while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n\n\n";
           cout<<" Enter Platinum price : ";
            cin>>t;
        }
         plat=stoi(t);
        cout<<" Enter Gold price : ";
        cin>>t;
           while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n\n\n";
         cout<<" Enter Gold price : ";
            cin>>t;
        }
         go=stoi(t);
        cout<<" Enter Silver price : ";
        cin>>t;
           while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n\n\n";
              cout<<" Enter Silver price : ";
            cin>>t;
        }
         silv=stoi(t);
                o1[t1-1].adminssetprice(plat,go,silv);}else cout<<" Enter valid details!\n";

                }
            }}

            else
                cout<<" Incorrect Password :(\n";
        }
    else if(choice==2)
    {cout<<endl<<endl;
         for(int i=0;i<3;i++)
        {
            o1[i].mseat(i);
            cout<<" SCREEN : "<<i+1<<" MOVIE : "<<moviename[i]<<endl;
        }
        cout<<endl<<endl;
    int screen,c;
    cout<<" 1 : Book a ticket  2: Cancel a ticet : ";
    cin>>t;

        while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n";
            cout<<" 1 : Book a ticket  2: Cancel a ticet : ";
            cin>>t;
        }
         c=stoi(t);

    cout<<endl<<endl;
    if(c==1)
    {
        int t1;
        cout<<" Enter no of tickets to be booked : ";
        cin>>t;
        while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n\n\n";
            cout<<" Enter no of tickets to be booked : ";
            cin>>t;
        }
         t1=stoi(t);
        while(t1){
        cout<<" Enter Screen : ";
        cin>>t;
           while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n\n\n";
            cout<<" Enter Screen : ";
            cin>>t;
        }
         screen=stoi(t);

        cout<<endl<<endl;
        if(screen>0&&screen<4){
        o1[screen-1].sdisplay(screen-1);
        o1[screen-1].sbook();t1--;}else cout<<" Please enter valid details!\n";
          for(int k=0;k<3;k++)
                            o1[k].txt(k);
                            counter=0;
        }
   }
    else if(c==2)
    {
        string choiceid;
        cout<<" Enter booking ID : ";
        cin>>t;
           while(!isNumeric1(t))
        {
            cout<<" Wrong Input!\n\n\n";
             cout<<" Enter booking ID : ";
            cin>>t;
        }
            choiceid=t;
        char z=choiceid[choiceid.length()-1];
        int a=stoi(&z);
        if(a<4&&a>0)
        {
            cout<<" THEATER : "<<a<<endl;
            o1[a-1].scancel(choiceid);
        }
        else
            cout<<" Wrong Booking Id\n";
    }

    }
    else if(!choice)
        exit(0);
    else
        cout<<"Wrong Input!";
}
    return 0;
}

