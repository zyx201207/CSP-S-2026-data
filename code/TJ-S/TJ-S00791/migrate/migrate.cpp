#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2145151],n,m;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			queue<int> que;
			int dis[n+10],cnt[n+10];
			que.push(i);
			memset(dis,0x3f3f,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			cnt[i]=1,dis[i]=0;
			while(!que.empty()){
				int u=que.front();
				que.pop();
				for(int v=i+1;v<=n;v++){
					if(x[v]-x[u]<=m){
						if(dis[u]+1<dis[v]){
							dis[v]=dis[u]+1;
							cnt[v]=cnt[u];
							que.push(v);
						}else if(dis[u]+1==dis[v]){
							cnt[v]+=cnt[u];
							que.push(v);
						}
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}
