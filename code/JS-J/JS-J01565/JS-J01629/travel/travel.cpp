#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int check(string s1,string s2)
{
    int x=s1[2]-'A',y=s2[2]-'A';
    if(x<=2&&y>=3)return 0;
    if(x>=3&&x<=2)return 0;
    if(abs(x-y)==1)return 1;
    return 0;
}
int cc(string s1,string s2)
{
    int x=s1[2]-'A',y=s2[2]-'A';
    if(x<=2&&y>=3)return 0;
    if(x>=3&&x<=2)return 0;
    return 1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<"1";
        if(b[0]==d[0]&&b[1]==d[1])
        {
            cout<<"1";
            if(cc(b,d)==1)
            {
                cout<<"1";
            }
            else cout<<"0";
            if(b[0]==d[0]&&b[1]==d[1])
            {
                if(check(b,d)==1)
                {
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"0";
        }
        else cout<<"000";
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
