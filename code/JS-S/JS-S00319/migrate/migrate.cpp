#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5005];
int g[5005][5005];
int cnt[5005][5005];
void dfs(int zu,int v,int duan){
    if(v<1||v>n)return ;
        if(a[v]-a[v-1]<=k){
            int y=duan+1;
            if(y<g[zu][v]||g[zu][v]==0){
                g[zu][v]=y;
                g[v][zu]=y;
                cnt[zu][v]=1;
                cnt[v][zu]=1;
            }else if(y==g[zu][v]){
                cnt[zu][v]++;
                cnt[v][zu]++;
            }
            //cout<<zu<<"-->"<<v<<" "<<y<<endl;
            for(int i=v+1;a[i]-a[v]<=k&&i<=n;i++){
                dfs(zu,i,y);
            }
        }else return ;
        return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long ans=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){

            for(int j=1;j+i<=n;j++)dfs(i,i+j,0);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<cnt[i][j]<<" ";
                if(cnt[i][j]==2)ans++;
            }cout<<endl;
        }
        //ans/=2;
        cout<<0<<endl;
    }
    return 0;
}
