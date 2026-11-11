#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
void dfs(int now,int sum,int t)
{
    if(t>m)
    {
        ans=max(ans,sum);
        return;
    }
    if(now>n) return;
    dfs(now+1,sum,t);
    dfs(now+1,sum&a[now],t+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    if(m==1)
    {
        cout<<a[1];
        return 0;
    }
    if(m==n)
    {
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    dfs(1,pow(2,30)-1,1);
    cout<<ans;
    return 0;
}
