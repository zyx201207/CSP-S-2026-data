#include<iostream>
#include<cstring>
using namespace std;
string n,m,a,b;
int c[100],e[100];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    cin>>a>>b;
    char d,f;
    if(n==a)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    for(int i=0;i<3;i++)
    {
        if(m[i]>='0' && m[i]<='9')
        {
            c[i]=m[i]-'0';
        }
        else
        {
           d=m[i];
        }
        if(b[i]>='0' && b[i]<='9')
        {
            e[i]=b[i]-'0';
        }
        else
        {
           f=b[i];
        }
    }
    if(c[0]==e[0]&&c[1]==e[1])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(d<='C'&&f<='C')
    {
        cout<<1;
        if(d+1==f||f+1==f)
        {
            cout<<1;
        }
        else
        {
			cout<<0;
		}
    }
    else if(d>='D'&&f<='D')
    {
        cout<<1;
        if(d+1==f||f+1==f)
        {
            cout<<1;
        }
    }
    else
    {
        cout<<0<<0;
    }
    return 0;
}
