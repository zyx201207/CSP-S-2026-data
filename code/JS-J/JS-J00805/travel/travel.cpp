#include<iostream>
using namespace std;
bool q;
long long read()
{
    q=0;
    int c,d=0;
    long long x=0;
    c=getchar();
    while(c<'0'||c>'9')
    {
        c=getchar();
        if(c==-1)
        {
            q=1;
            return 0;
        }
        d=c;

    }
    while(c>='0'&&c<='9'||c==-1)
    {
        x=x*10+c-'0';
        c=getchar();
    }
    if(d=='-')
    {
        x*=-1;
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,k;
    int c=0,d=0;
    char e,f;
    a=read();
    k=getchar();
    c=k-48;
    k=getchar();
    c=c*10+k-48;
    e=getchar();
    b=read();
    k=getchar();
    d=k-48;
    k=getchar();
    d=d*10+k-48;
    f=getchar();
    if(a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(c==d&&a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(a==b&&c==d&&((e>='A'&&e<='C'&&f>='A'&&f<='C')||(e>='D'&&e<='F'&&f>='D'&&f<='F')))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(a==b&&c==d&&((e>='A'&&e<='C'&&f>='A'&&f<='C')||(e>='D'&&e<='F'&&f>='D'&&f<='F'))&&(e-f==1||f-e==1))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
