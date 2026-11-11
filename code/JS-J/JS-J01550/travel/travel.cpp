#include<bits/stdc++.h>//"An interesting Train."
using namespace std;//"But Wht Don't You Sit First And Look Around?

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int a=1,b=1,c=1,d=1;
    if(c1!=c2)a=0,b=0,c=0,d=0;
    int s3=(s1[0]-48)*10+s1[1]-48;
    int s4=(s2[0]-48)*10+s2[1]-48;
    if(s3!=s4)b=0,c=0,d=0;
    char c3=s1[2],c4=s2[2];
    if(c3=='A')
    {
        if(c4=='D'||c4=='E')c=0,d=0;
        if(c4=='C')d=0;
    }
    else if(c3=='B')
    {
        if(c4=='D'||c4=='E')c=0,d=0;
    }
    else if(c3=='C')
    {
        if(c4=='D'||c4=='E')c=0,d=0;
        if(c4=='A')d=0;
    }
    else if(c3=='D')
    {
        if(c4=='A'||c4=='B'||c4=='C')c=0,d=0;
    }
    else if(c3=='F')
    {
        if(c4=='A'||c4=='B'||c4=='C')c=0,d=0;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
