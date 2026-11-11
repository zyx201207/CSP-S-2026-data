# include<bits/stdc++.h>
using namespace std;
# define int long long
int c,t,n,m,a[100005],b[100005];
int g[10][10];
void dfs(int x,int cnt,int end_){
    if(x==end_){
        b[cnt%100005]++;
        return;
    }
    for(int i=x+1;i<=end_;i++){
        if(g[x][i]&&g[x][i]<=m) dfs(i,cnt+1,end_);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    if(c<=2){
        while(t--){
            int ans = 0;
            cin >> n >> m;
            for(int i=1;i<=n;i++) cin >> a[i];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i!=j) g[i][j] = abs(a[i]-a[j]);
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    dfs(i,0,j);
                    int k = 0;
                    while(!b[k%100005]) k++;
                    if(b[k%100005]==2) ans++;
                    for(int i=1;i<=100004;i++) b[i] = 0;
                }
            }
            cout << ans<<endl;
        }
    }
    return 0;
}
