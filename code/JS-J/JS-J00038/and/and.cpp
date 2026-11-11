#include<bits/stdc++.h>
#define int long long
#define ln "\n"
using namespace std;
const int N=2e5+10;
int a[N];
int ans=0;
int n,k;
void dfs(int x,int f,int cnt)
{
    //cout<<x<<ln;
    if(x>k)
    {
       // cout<<"a"<<cnt<<ln;
        ans=max(ans,cnt);
        return ;
    }
    if(f==n)
    {
        return ;
    }
    for(int i=f+1;i<=n;i++)
    {
        if(x==1) dfs(x+1,i,a[i]);
        else dfs(x+1,i,cnt&a[i]);
    }
    return ;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans<<ln;
    return 0;
}