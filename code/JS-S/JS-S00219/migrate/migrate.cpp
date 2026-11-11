#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define endl '\n'
const int maxn=3e2+10;
int x[maxn];
vector<int>g[maxn];
int dis[maxn][maxn];
int tot[maxn][maxn];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)g[i].clear();
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                    dis[i][j]=dis[j][i]=1;
                }
            }
        }
        for(int i=1;i<=n;i++)dis[i][i]=0;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(dis[i][j]==dis[i][k]+dis[k][j]){
                        tot[i][j]++;
                    }
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                        tot[i][j]=0;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(tot[i][j]==1)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
