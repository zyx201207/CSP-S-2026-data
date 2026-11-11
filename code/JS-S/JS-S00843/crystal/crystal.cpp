#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
bool q;
long long readint()
{
    q=0;
    int c,d;
    long long a=0;
    c=getchar();
    while(c<'0'||c>'9')
    {
        if(c==EOF)
        {
            q=1;
            return 0;
        }
        d=c;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=a*10+c-48;
        c=getchar();
    }
    if(d=='-')
    {
        a*=-1;
    }
    return a;
}
bool tmp(long long a,long long b)
{
    return a<b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,nu=0,ans=0;
    n=readint();
    m=readint();
    vector<long long> a(n);
    for(long long i=0;i<n;i++)
    {
        a[i]=readint();
    }
    sort(a.begin(),a.end(),tmp);
    queue<long long> c;
    c.push(a[0]);
    for(long long i=1;i<n;i++)
    {
        while((a[i]-a[i-1])*c.size()>m-nu)
        {
            nu=nu-(a[i-1]-c.front());
            c.pop();
        }
        nu+=(a[i]-a[i-1])*c.size();
        c.push(a[i]);
        if(c.size()>ans)
        {
            ans=c.size();
        }
    }
    cout<<ans<<endl;
    return 0;
}
