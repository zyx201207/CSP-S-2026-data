#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+10;
int n,m;
int a[M];
int res;
void solve(int u,int val,int cnt)
{
    if(cnt==m)
    {
        res=max(res,val);
        return ;
    }
    if(u>n) return ;
    solve(u+1,val & a[u],cnt+1);
    solve(u+1,val,cnt);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(n<=20)
    {
        int sum=1;
        for(int i=1;i<=30;++i) sum*=2;
        solve(1,sum,0);
        cout<<res<<endl;
        return 0;
    }
    if(n<=2000)
    {
        if(m==1) cout<<*max_element(a+1,a+n+1)<<endl;
        else if(m==2)
        {
            int ans=0;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<i;++j)
                {
                    ans=max(ans,a[i] & a[j]);
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            int ans=a[1];
            for(int i=2;i<=n;++i) ans=ans & a[i];
            cout<<ans<<endl;
        }
        return 0;
    }
    sort(a+1,a+n+1);
    cout<<a[m]<<endl;
    return 0;
}
