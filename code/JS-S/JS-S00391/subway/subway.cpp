#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int read()
{
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
        {
            f=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        k=k*10+(c-'0');
        c=getchar();
    }
    return k*f;
}
void write(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x<10)
    {
        putchar(x+'0');
    }
    else
    {
        write(x/10);
        putchar(x%10+'0');
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    return 0;
}
