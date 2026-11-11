#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll s[N],n,m,ans=0,maxa=0;
void dfs(ll step,ll andd,ll use)
{
    if(use==m)
    {
        ans=max(ans,andd);
        return;
    }
    if(step>n) return;
    dfs(step+1,andd&s[step+1],use+1);
    dfs(step+1,andd,use);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
    {
        cin>>s[i];
        maxa=max(s[i],maxa);
    }
    if(n<=20)
    {
        for(int i=1;i<=n-m+1;++i)
        {
            dfs(i,s[i],1);
        }
    }
    else if(m==1)
    {
        for(int i=1;i<=n;++i) ans=max(ans,s[i]);
    }
    else if(m==n)
    {
        ans=s[1];
        for(int i=2;i<=n;++i) ans&=s[i];
    }
    else if(m==2)
    {
        for(int i=1;i<n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                ans=max(ans,s[i]&s[j]);
            }
        }
    }
    else if(maxa<=4)
    {
        cout<<1;
        return 0;
    }
    cout<<ans;
    return 0;
}
