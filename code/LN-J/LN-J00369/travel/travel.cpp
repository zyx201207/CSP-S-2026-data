#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=0,b=0,c=0,d=0;
    a=(c1==c2);
    int l1=(s1[0]-'0')*10+(s1[1]-'0'),l2=(s2[0]-'0')*10+s2[1]-'0';
    b=(a&&l1==l2);
    if(b)
    {
        int  x,y;
        x=s1[2]-'A';
        y=s2[2]-'A';
        if(x<3&&y<3)
        {
            c=1;
            d=(abs(x-y)==1);
        }
        if(x>=3&&y>=3)
        {
            c=1;
            d=1;
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
