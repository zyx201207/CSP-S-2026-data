#include<bits/stdc++.h>
#define int long long
#define prr pair<pair<int,int>,int>
using namespace std;
int c,n,m,d,Q,W[500005],k,u,v[500005],w,x,y,dis[500005],vis[500005],ans;
vector<pair<int,int>>ve[500005];
priority_queue<prr,vector<prr>,greater<prr>>q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v[j]>>w;
			ve[u].push_back({i*d+v[j],w});
			ve[i*d+v[j]].push_back({u,w});
			for(int t=1;t<=j;t++){
				ve[i*d+v[t]].push_back({i*d+v[j],0});
				ve[i*d+v[j]].push_back({i*d+v[t],0});
			}
		}
	}
	while(Q--){
		cin>>x>>y;
		memset(dis,0x3f,sizeof(dis));
		for(int k=0;k<=n;k++){
			dis[k*d+x]=0;
			q.push({{0,k*d+x},k*d+x});
			ans=0;
			while(!q.empty()){
				int u=q.top().first.second,e=q.top().second;
				q.pop();
				if(vis[u]==Q){
					continue;
				}
				vis[u]=Q;
				for(auto i:ve[u]){
					int v=i.first;
					int w=i.second;
					if(u==0&&abs(e-v)%d!=0){
						continue;
					}
					if(dis[v]>dis[u]+w){
						dis[v]=dis[u]+w;
						if(w==0){
							q.push({{dis[v],v},v});
						}else{
							q.push({{dis[v],v},e});
						}
					}
				}
			}
			for(int i=0;i<=n;i++){
				ans=max(dis[y+i*d],ans);
			}
		}
		cout<<ans+W[x]+W[y]<<"\n";
	}
	return 0;
}

