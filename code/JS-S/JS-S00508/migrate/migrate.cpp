#include <bits/stdc++.h>
using namespace std;
long long c,t;
const int N=2e6+5;
long long a[N];
int minn=N;
int ans=0;
long long n,d;
long long read()
{
    char c;
    c=getchar();
    bool e=false;
    while(c<'0'||c>'9')
    {
        if(c=='-')
        {
            e=true;
        }
        c=getchar();
    }
    long long x=0;
    while(c>='0'&&c<='9')
    {
        x*=10;
        x+=(c-'0');
        c=getchar();
    }
    if(e)
    {
        x=-x;
    }
    return x;
}
void dfs(int l,int r,int pos)
{
    if(l==r)
    {
        if(minn>pos)
        {
            minn=pos;
            ans=1;
        }
        else if(minn==pos)ans++;
        //cout<<minn<<" "<<ans<<"\n";
        return;
    }
    for(int i=l+1;i<=r;i++)
    {
        if(a[i]-a[l]<=d)
        {
            pos++;
            if(pos>minn)break;
            //cout<<i<<" "<<r<<" "<<pos<<"\n";
            dfs(i,r,pos);
            pos--;
        }
    }
}
void solve()
{
    n=read();
    d=read();
    long long q=0;
    bool oo=true;
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        if(i>2)
        {
            if(a[i]-a[i-1]!=a[i-1]-a[i-2])
            {
                oo=false;
            }
        }
    }
    if(oo)
    {
        int pp=a[2]-a[1];
        if(d<pp*2)
        {
            cout<<"0\n";
            return;
        }
        else
        {
            int y=d/pp;
            cout<<n-2*y+1<<"\n";
            return;
        }
    }
    for(int i=1;i<=n-3;i++)
    {
        for(int j=i+3;j<=n;j++)
        {
            ans=0;
            minn=N;
            dfs(i,j,2);
            if(ans==2)
            {
                q++;
            }
        }
    }
    cout<<q<<"\n";
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    t=read();
    while(t--)
    {
        solve();
    }
    return 0;
}
