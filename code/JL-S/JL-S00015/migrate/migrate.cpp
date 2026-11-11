#include<bits/stdc++.h>
using namespace std;
int n;
int c,t;
long long d,x[2200000];
int cnt[330][330];
int dis[330][330];
bool vis[330][330];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n<=300){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    vis[i][j]=false;
                    cnt[i][j]=0;
                }
            }
            for(int i=1;i<=n;i++){
                queue<pair<int,int>>q;
                q.push({i,0});
                while(!q.empty()){
                    int t=q.front().first;
                    int dt=q.front().second;
                    q.pop();
                    if(vis[i][t]&&dt==dis[i][t]){
                        cnt[i][t]++;
                        continue;
                    }else if(vis[i][t]) continue;
                    dis[i][t]=dt;
                    cnt[i][t]=1;
                    vis[i][t]=true;
                    for(int j=t+1;j<=n&&x[j]-x[t]<=d;j++){
                        if(!vis[i][j]) q.push({j,dt+1});
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(cnt[i][j]==2) ans++;
                }
            }
            cout<<ans<<'\n';
        }else{
            cout<<(d/(x[2]-x[1])==1?0:max(n-d/llabs(x[2]-x[1])*2+1,0ll))<<'\n';
        }
	}
	return 0;
}
