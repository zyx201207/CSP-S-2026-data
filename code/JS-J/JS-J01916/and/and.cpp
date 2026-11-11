#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],m,ans,b[200005],s,c[200005];
vector<int> g[200005];
bool check(int x)
{
    int t=0,tmp=1;
    for(int i=0;i<g[x].size();i++)
    {
        while(b[tmp]<g[x][i]&&tmp<=s)
        {
            tmp++;
        }
        if(b[tmp]==g[x][i])
        {
            t++;
            c[t]=b[tmp];
        }
    }
    if(t>=m)
    {
        memset(b,0,sizeof(b));
        for(int i=1;i<=t;i++)
        {
            b[i]=c[i];
        }
        s=t;
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long zd=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        zd=max(zd,a[i]);
        for(int j=0;j<=30;j++)
        {
            if(a[i]&(long long)(1<<j))
            {
                g[j].push_back(i);
            }
        }
    }
    if(m==1)
    {
        cout<<zd;
        return 0;
    }
    for(int i=30;i>=0;i--)
    {
        if(g[i].size()>=m)
        {
            if(s==0)
            {
                ans+=(1<<i);
                s=g[i].size();
                for(int j=1;j<=g[i].size();j++)
                {
                    b[j]=g[i][j-1];
                }
            }
            else if(check(i))
            {
                ans+=(1<<i);
            }
        }
    }
    cout<<ans;
    return 0;
}
