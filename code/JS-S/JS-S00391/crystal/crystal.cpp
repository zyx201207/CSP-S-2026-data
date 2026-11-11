#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn];
bool vis;int d;//special A,B
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
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        if(i==2)
        {
            d=a[i]-a[i-1];
        }
        else if(i>2)
        {
            if((a[i]-a[i-1])!=d)vis=true;
        }
    }
    if(!vis)
    {
        int x=m;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(x-i*abs(d)>=0)
            {
                x-=i*abs(d);
                cnt++;
            }
            else break;
        }
        write(cnt);
        putchar('\n');
    }
    else{
        sort(a+1,a+n+1);
        int maxans=0,x=0;
        for(int i=n;i>=1;i--)
        {
            int cnt=1;
            x=m;
            for(int j=i-1;j>=1;j--)
            {
                if(x>=a[i]-a[j])
                {
                    cnt++;
                    x-=(a[i]-a[j]);
                }
                else break;
            }
            maxans=max(maxans,cnt);
            if(maxans>=i-1)break;
            else continue;
        }
        write(maxans);
        putchar('\n');
    }
    return 0;
}

