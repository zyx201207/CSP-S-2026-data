#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    //1.两张车票对应的座位是否在同一节车厢；
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    //2.两张车票对应的座位是否在同一节车厢的同一排
    if(s1.substr(0,2)==s2.substr(0,2)&&c1==c2)
    {
        cout<<1;
        //3.两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
       if((s1.substr(2,1)=="F"&&s2.substr(2,1)=="F")||
         (s1.substr(2,1)=="F"&&s2.substr(2,1)=="D")||
         (s1.substr(2,1)=="D"&&s2.substr(2,1)=="F")||
         (s1.substr(2,1)=="D"&&s2.substr(2,1)=="D")||
         (s1.substr(2,1)=="C"&&s2.substr(2,1)=="C")||
         (s1.substr(2,1)=="C"&&s2.substr(2,1)=="B")||
         (s1.substr(2,1)=="C"&&s2.substr(2,1)=="A")||
         (s1.substr(2,1)=="B"&&s2.substr(2,1)=="C")||
         (s1.substr(2,1)=="B"&&s2.substr(2,1)=="B")||
         (s1.substr(2,1)=="B"&&s2.substr(2,1)=="A")||
         (s1.substr(2,1)=="A"&&s2.substr(2,1)=="C")||
         (s1.substr(2,1)=="A"&&s2.substr(2,1)=="B")||
         (s1.substr(2,1)=="A"&&s2.substr(2,1)=="A"))
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
        cout<<0<<0;
    }
    //4.两张车票对应的座位是否相邻
    if((s1.substr(2,1)=="F"&&s2.substr(2,1)=="F")||
        (s1.substr(2,1)=="F"&&s2.substr(2,1)=="D")||
        (s1.substr(2,1)=="D"&&s2.substr(2,1)=="F")||
        (s1.substr(2,1)=="D"&&s2.substr(2,1)=="D"))
    {
        if(s1.substr(0,2)==s2.substr(0,2))
        {
            cout<<1;
        }
    }
   else if((s1.substr(2,1)=="C"&&s2.substr(2,1)=="C")||
    (s1.substr(2,1)=="C"&&s2.substr(2,1)=="B")||
    (s1.substr(2,1)=="B"&&s2.substr(2,1)=="C")||
    (s1.substr(2,1)=="B"&&s2.substr(2,1)=="A")||
    (s1.substr(2,1)=="A"&&s2.substr(2,1)=="B"))
   {
       if(s1.substr(0,2)==s2.substr(0,2))
       {
           cout<<1;
       }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
