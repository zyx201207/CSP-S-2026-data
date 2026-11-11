#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn =5010;
int a[maxn];
int b[maxn];
int vis[maxn];
int ans;
int n,m;
void dfs(int pos){
    int sum=0;
    if(pos==m){
        sum=pow(2,31)-1;
        for(int i=1;i<=n;i++){
            if(vis[i]==0) continue;
            sum=sum&b[i];
        }
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1) continue;
        b[i]=a[i];
        vis[i]=1;
        dfs(pos+1);
        vis[i]=0;
        b[i]=0;
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans2=0;
    if(n==m){
        ans=a[1];
        for(int i=2;i<=n;i++) ans=ans&a[i];
        cout<<ans;
        return 0;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans2=max(ans2,a[i]&a[j]);
            }
        }
        cout<<ans2;
        return 0;
    }else{
        dfs(0);
        cout<<ans;
    }
    return 0;
}
