#include<bits/stdc++.h>
#define int long long
#define sor(i,l,r) for(int i=(l);i<=(r);i++)
#define ros(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
namespace Eaux{
	const int N=600005;
	int c,n,m,d,q;
	vector<vector<pair<int,int> > > g;
	int w[N];
	void dij(int s){
		bitset<1000005> vis;
		
	}
	void work(){
		cin>>c>>n>>m>>d>>q;
		g.resize(n+m+1);
		sor(i,1,m) cin>>w[i];
		int Y=0;
		sor(i,1,n){
			int k;
			cin>>k;
			sor(j,1,k){
				int x,y;
				cin>>x>>y;
				if(Y==0) {
					Y=y;
				} else if(Y==y){
					Y=y;
				} else{
					Y=-1;
				}
				g[x].push_back(make_pair(m+i,y));
				g[m+i].push_back(make_pair(x,y));
			}
		}
		if(Y!=-1){
			#undef int
			vector<vector<int> > dis(n+1,vector<int>(n+m+1));
			sor(s,m+1,n+m){
				sor(i,1,n+m) dis[s-m][i]=1e9;
				dis[s-m][s]=0;
				queue<int> q;
				q.push(s);
				while(!q.empty()){
					int u=q.front();
					q.pop();
					for(pair<int,int> v:g[u]){
						if(dis[s-m][v.first]==1e9){
							dis[s-m][v.first]=dis[s-m][u]+1;
							q.push(v.first);
						}
					} 
				}
			}
			while(q--){
				int u,v,ans=1e9;
				cin>>u>>v;
				sor(i,1,n) ans=min(ans,dis[i][u]+dis[i][v]);
				cout<<(long long)(ans*Y+w[u]+w[v])<<"\n";
			}
			#define int long long
		}
		vector<vector<int> > dis(n+1,vector<int>(n+m+1));
		sor(s,m+1,n+m){
			sor(i,1,n+m) dis[s-m][i]=1e16;
			dis[s-m][s]=0;
			priority_queue<pair<int,int> > q;
			q.push({0,s});
			while(!q.empty()){
				pair<int,int> u=q.top();
				q.pop();
				//cout<<u.first<<" "<<u.second<<endl;
				for(pair<int,int> v:g[u.second]){
					if(dis[s-m][v.first]==1e16){
						dis[s-m][v.first]=dis[s-m][u.second]+v.second;
						q.push(make_pair(-dis[s-m][v.first],v.first));
					} 
					else{
						if(dis[s-m][u.second]+v.second<dis[s-m][v.first]){
							dis[s-m][v.first]=dis[s-m][u.second]+v.second;
							q.push(make_pair(-dis[s-m][v.first],v.first));
						}
					}
				} 
			}
		}
		while(q--){
			int u,v,ans=1e16;
			cin>>u>>v;
			sor(i,1,n) ans=min(ans,dis[i][u]+dis[i][v]);
			cout<<ans+w[u]+w[v]<<"\n";
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Eaux::work();
	return 0;
}
