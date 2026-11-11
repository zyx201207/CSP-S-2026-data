#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int get(char c)
{
    if (c<='C')return 1;
    return 2;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if (s1!=s3)
    {
        cout<<"0000";
        return 0;
    }
    string a=s2.substr(0,2);
    string b=s4.substr(0,2);
    if (a!=b)
    {
        cout<<"1000";
        return 0;
    }
    char c=s2[2],d=s4[2];
    if (c=='D')c='E';
    if (d=='D')d='E';
    if (get(c)!=get(d))
    {
        cout<<"1100";
        return 0;
    }
    if ((int)c-1==d||(int)d-1==c)cout<<"1111";
    else cout<<"1110";
    return 0;
}