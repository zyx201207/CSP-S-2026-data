#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+5;
ll w[N];
vector<pair<int,ll>> u[N];
vector<int> edge[N];
int c,n,m,d,q;
ll dist[N][30];
struct node{
	int line,u,w;
	bool friend operator < (const node &x,const node &y){
		return x.w>y.w;
	}
};
ll dj(int s,int t){
	ll ans=w[s]+w[t];
	priority_queue<node> q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=d;j++){
			dist[i][j]=1e18;
		}
	}
	for(pair<int,int> v : u[s]){
		dist[s][v.first]=v.second;
		q.push({v.first,s,v.second});	
	}
	while(!q.empty()){
		node tt=q.top();
		q.pop();
		for(int v : edge[tt.u]){
			bool ok=0;
			ll w=0;
			for(pair<int,int> tmp : u[v]){
				if(tmp.first==tt.line){
					ok=1;
					w=tmp.second;	
					break;
				}
			}
			if(!ok) continue ;
			//cout<<v<<'\n';
			if(dist[v][tt.line]>dist[tt.u][tt.line]+w){
				dist[v][tt.line]=dist[tt.u][tt.line]+w;
				//cout<<v<<" "<<dist[v][tt.line]<<'\n';
				for(pair<int,int> tmp : u[v]){
					if(dist[v][tmp.first]>dist[v][tt.line]+tmp.second){
						dist[v][tmp.first]=dist[v][tt.line]+tmp.second;
						q.push({tmp.first,v,dist[v][tmp.first]});
					}
				}
				q.push({tt.line,v,dist[v][tt.line]});
			}
		}
	}
	ll p=1e18;
	for(int i=1;i<=n;i++){
		p=min(p,dist[t][i]);
	}
	return ans+p;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		vector<int> a(k);
		vector<int> t(k);
		for(int j=0;j<k;j++){
			cin>>a[j]>>t[j];
			if(j!=0){
				edge[a[j]].push_back(a[j-1]);
				edge[a[j-1]].push_back(a[j]);
			}
			if(j==n){
				edge[a[j]].push_back(a[0]);
				edge[a[0]].push_back(a[j]);
			}
			u[a[j]].push_back({i,t[j]}); 
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		cout<<dj(s,t)<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
