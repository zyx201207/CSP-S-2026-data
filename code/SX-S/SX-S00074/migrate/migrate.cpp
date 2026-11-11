#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
priority_queue<PII,vector<PII>,greater<PII>> q;
int dis[2000005],dis1[2000006],dis2[2000005],x[2000005];;
vector<PII> h[500005];
void dj(int s){
	q.push({0,s});
	memset(dis,63,sizeof(dis));
	memset(dis1,63,sizeof(dis1));
	memset(dis2,63,sizeof(dis2));
	dis[s]=0;
	dis1[s]=0;
	dis2[s]=0;
	while(!q.empty()){
		int x=q.top().fi;
		int y=q.top().se;
		q.pop();
		if(dis[y]!=x) continue;
		for(auto ed:h[y]){
			int u=ed.fi;
			int v=ed.se;
			if(dis[u]>dis[y]+v){
				dis2[u]=dis1[u];
				dis1[u]=dis[u];
				dis[u]=dis[y]+v;
				q.push({dis[u],u});
			}else if(dis1[u]>dis[y]+v){
				dis2[u]=dis1[u];
				dis1[u]=dis[y]+v;
				q.push({dis1[u],u});
			}else if(dis2[u]>dis[y]+v){
				dis2[u]=dis[y]+v;
				q.push({dis2[u],u});
			}else if(dis2[u]>dis1[y]+v){
				dis2[u]=dis1[y]+v;
				q.push({dis2[u],u});
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin >>c>>t;
	while(t--){
		int n,d;cin >>n>>d;
		memset(x,0,sizeof(x));
		memset(h,0,sizeof(h));
		for(int i=1;i<=n;++i){
			cin >>x[i];
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(x[j]-x[i]<=d){
					h[i].push_back({j,x[j]-x[i]});
					h[j].push_back({i,x[j]-x[i]});

				}else{
					break;
				}
			}
		}
		int zs=0;
		for(int i=1;i<=n;++i){
			dj(i);
			for(int j=i+1;j<=n;++j){
				if(dis[j]==dis1[j]&&dis[j]<dis2[j]&&dis[j]!=0&&dis1[j]!=0){
					zs++;
				}
			}
		}
		cout<<zs<<endl;
	}
	return 0;
}