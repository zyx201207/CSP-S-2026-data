#include <bits/stdc++.h>

using namespace std;
int a,b,d,e;
char c,f;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a>>b>>c>>d>>e>>f;
    bool flag=true;
    if(a==d)
        cout<<1;
    else
    {
        flag=false;
        cout<<0;
    }

    if(b==e&&flag==true)
        cout<<1;
    else
    {
        flag=false;
        cout<<0;
    }

    if(f>='A'&&f<='C'&&c>='A'&&c<='C'&&flag==true||f>='D'&&f<='F'&&c>='D'&&c<='F'&&flag==true){
        cout<<1;
    }
    else
    {
        flag=false;
        cout<<0;
    }

    if(flag==true&&abs(f-c)==1)
        cout<<1;
    else if(f=='D'&&c=='F'&&flag==true||f=='F'&&c=='D'&&flag==true)
        cout<<1;
    else
        cout<<0;
    return 0;
}
