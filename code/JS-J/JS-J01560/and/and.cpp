#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m;
long long dp[N],a[N],ans,cnt[50];
void ct(long long a)
{
    int xb=0;
    while(a!=0)
    {
        xb++;
        if (a&1)cnt[xb]++;
        a>>=1;
    }
}
void dfs_(int xb,long long k,int fl)
{
    if (fl>=m)
    {
        ans=max(ans,k);
        return;
    }
    for (int i=xb+1;i<=n;i++)
        dfs_(i,k&a[i],fl+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<=20)
    {
        for (int i=1;i<=n;i++) dfs_(i,a[i],1);
        cout<<ans;
    }
    else
    {
        if (m==1)
        {
            for (int i=1;i<=n;i++) ans=max(ans,a[i]);
            cout<<ans;
        }
        else if (m==2)
        {
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;j++)
                    ans=max(ans,a[i]&a[j]);
            cout<<ans;
        }
        else if (m==n)
        {
            for (int i=1;i<=n;i++) ans&=a[i];
            cout<<ans;
        }
        else
        {
            for (int i=1;i<=n;i++) ct(a[i]);
            for (int i=1;i<=50;i++)
            {
                if (cnt[i]>=m)
                {
                    if (i==1) ans+=1;
                    else ans+=pow(2,i-1);
                }
            }
            cout<<ans;
        }
    }
    return 0;
}
