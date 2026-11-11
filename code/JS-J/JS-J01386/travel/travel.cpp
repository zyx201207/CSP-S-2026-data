#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,pai1,pai2,zi1,zi2;
bool flag;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }//problem1
    pai1 = s1.substr(0,2);
    pai2 = s2.substr(0,2);
    if(c1==c2&&pai1==pai2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }//problem2
    zi1 = s1[2];
    zi2 = s2[2];
    if(c1==c2&&pai1==pai2)
    {
        if((zi1=="A"&&(zi2=="B"||zi2=="C"))
         ||(zi1=="B"&&(zi2=="A"||zi2=="C"))
         ||(zi1=="C"&&(zi2=="B"||zi2=="A"))
         ||(zi1=="D"&&zi2=="F")
         ||(zi1=="F"&&zi2=="D"))
        {
            cout<<1;
            flag = 1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        cout<<0;
    }//problem3
    if(flag==1)//ABC DF
    {//AB BA BC CB DF FD
        if((zi1=="A"&&zi2=="B")||(zi1=="B"&&zi2=="A")||(zi1=="B"&&zi2=="C")||(zi1=="C"&&zi2=="B")||(zi1=="D"&&zi2=="F")
           ||(zi1=="F"&&zi2=="D"))
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
