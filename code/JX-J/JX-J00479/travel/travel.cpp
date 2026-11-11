#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f(string s)
{
    int sum=0;
    for(int i=0;i<2;i++)
        sum+=s[i]-'0';
    return sum;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int cx1=f(c1),cx2=f(c2),h1=f(s1),h2=f(s2);
    char z1=s1[2],z2=s2[2];
    if(cx1!=cx2)
    {
        cout<<"0000";
        return 0;
    }
    if(h1!=h2)
    {
        cout<<"1000";
        return 0;
    }
    if(z1<='C'&&z2>='D'||z1>='D'&&z2<='C')
    {
        cout<<"1100";
        return 0;
    }
    if(abs(z1-z2)!=1)
    {
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
