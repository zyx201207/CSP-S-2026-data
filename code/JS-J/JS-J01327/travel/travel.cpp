#include<bits/stdc++.h>
using namespace std;
int ans(string x)
{
    int h=0;
    for(int i=0;i<x.size();i++)
        h=h*10+x[i]-'0';
    return h;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string e=b.substr(0,2),f=d.substr(0,2);
    if(ans(a)==ans(c))
    {
        cout<<1;
        if(ans(e)==ans(f))
        {
            cout<<1;
            char r=b[2],t=d[2];
            if(r>t)
                swap(r,t);
            if('A'<=r&&r<='C'&&t>'C')
            {
                cout<<"00";
            }
            else
            {
                cout<<1;
                cout<<(r=='A'&&t=='B' || r=='B'&&t=='C' || r=='D'&&t=='F');
            }
        }
        else
            cout<<"000";
    }
    else
    {
        cout<<"0000";
    }
}
