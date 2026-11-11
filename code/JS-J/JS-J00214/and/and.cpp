#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],c[2000005],ans=0;
inline void dfs(int i,int s){
    if(i==n+1&&s<m)return;
    if(s==m||i==n+1){
        int cnt=c[1];
        for(int j=2;j<=m;j++)cnt=cnt&c[j];
        ans=max(ans,cnt);
        return;
    }
    dfs(i+1,s);
    s++;
    c[s]=a[i];
    dfs(i+1,s);
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,0);
    cout<<ans;
    return 0;
}
