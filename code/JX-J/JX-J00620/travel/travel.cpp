#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;//c1, c2是01到17之间除01和16外的两位车厢号

    //两个座位相邻，当且仅当在同一节车厢的同一排，位于过道的同一侧 ,且在该侧的座位序列中相邻

    //两张车票对应的座位是否在同一节车厢
    int flag;
    if(c1==c2)cout<<1,flag=1;
    else cout<<0,flag=0;

    //两张车票对应的座位是否在同一节车厢的同一排
    string a,b;
    for(int i=0;i<=1;i++)
    {
        a+=s1[i];
        b+=s2[i];
    }
    int flag1;
    if(flag)
    {
        if(a==b)cout<<1,flag1=1;
        else cout<<0,flag1=0;
    }

    else cout<<0,flag1=0;

    //两张车票对应的座位是否位于过道的同一侧
    a=toupper(s1[2]);
    b=toupper(s2[2]);
    int flag2;
    if(flag1)
    {
        if( (a=="C"||a=="B"||a=="A") && (b=="C"||b=="B"||b=="A"))cout<<1,flag2=1;
        else if( (a=="F"||a=="D") && (b=="F"||b=="D") )cout<<1,flag2=1;
        else cout<<0,flag2=0;
    }
    else cout<<0,flag2=0;


    //两张车票对应的座位是否相邻
    //cout<<endl<<a<<" "<<b<<endl;
    if(flag2==1)
    {
        if((a=="C"&&b=="A") || (b=="C"&&a=="A"))cout<<0;
        else cout<<1;
    }

    else cout<<0;


    return 0;
}
