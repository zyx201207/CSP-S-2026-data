#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],cnt[N][30],ans;
bool vis[N];
void dfs(int cnt,int tmp){
    if (cnt==m+1){
        ans=max(ans,tmp);
        return;
    }
    for (int j=1;j<=n;j++){
        if (!vis[j]){
            vis[j]=1;
            dfs(cnt+1,tmp&a[j]);
            vis[j]=0;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        for (int j=0;j<=30;j++){
            if (a[i]&(1<<j))
                cnt[i][j]=1,cnt[n+1][j]++;
        }
    }
    if (n<=20){
        for (int i=1;i<=n;i++)
            dfs(1,a[i]);
        cout<<ans;
    }
    else if (m==n){
        ans=a[1];
        for (int i=2;i<=n;i++)
            ans&=a[i];
        cout<<ans;
    }
    else if (m==n-1){
        for (int i=1;i<=n;i++){
            int tmp=0;
            for (int j=0;j<=30;j++)
                if (cnt[n+1][j]-cnt[i][j]>=m)
                    tmp+=(1<<j);
            ans=max(ans,tmp);
        }
        cout<<ans;
    }else if (m==1){
        for (int i=1;i<=n;i++)
            ans=max(ans,a[i]);
        cout<<ans;
    }else if (m==2){
        for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            if (i==j)
                continue;
            ans=max(ans,a[i]&a[j]);
        }
        cout<<ans;
    }
    return 0;
}
