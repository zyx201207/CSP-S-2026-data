#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int n,m;
int ans=0;

int calc()
{
    map<int,int> mapp;
    int ret=0;
    for(int i=1;i<=n;i++) mapp[a[i]]=mapp[a[i]]+1,ret=max(ret,mapp[a[i]]);
    return ret;
}
void dfs(int k)
{
    if(k==0)
    {
        ans=max(ans,calc());
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]++;
        dfs(k-1);
        a[i]--;
    }
}
bool check1()
{
    for(int i=1;i<=n;i++) if(a[i]!=i) return false;
    return true;
}
bool check2()
{
    for(int i=1;i<=n-2;i++)
    {
        if(a[i]-a[i+1]!=a[i+1]-a[i+2]) return false;
    }
    return true;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }

    if(check1())
    {
        int sum=0;
        for(int i=1;i<=10000000;i++)
        {
            sum+=i;
            if(sum>m)
            {
                cout<<min(i,n);
                return 0;
            }
        }
    }
    else if(check2())
    {
        int d=abs(a[1]-a[2]);
        int sum=0;
        for(int i=1;i<=1000000;i++)
        {
            sum+=i*d;
            if(sum>m)
            {
                cout<<i;
                return 0;
            }
        }
    }
    else
    {
        dfs(m);
        cout<<ans;
    }
    return 0;
}
