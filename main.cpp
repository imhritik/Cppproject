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
node head=NULL;
node last=NULL;

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
   void sdisplay()
   {
    node temp=head;

    for(int i=0;i<(p+g+s);i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<"  "<<temp->row<<temp->no;
            temp=temp->next;
        }
        cout<<endl;
    }
    }

};



using namespace std;

int main()
{

    display o1;
    o1.mseat();
    o1.sdisplay();
    return 0;
}
