#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
struct edge{
	int w;int v;
};
int c,n,m,d,q;
int w[M],a[M],t[M];
vector<vector<edge> > mp(M);
bool v[M];int dist[M];
void dj(int s){
	memset(v,0,sizeof(v));
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	for(int i=1;i<=m*m+m;++i){
		int x=0,mind=0x3f3f3f3f;
		for(int j=1;j<=m*m+m;++j){
			if(!v[j]&&dist[j]<mind){
				mind=dist[j];
				x=j;
			}
		}
		v[x]=1;
		for(auto ed:mp[x]){
			int j=ed.w,po=ed.v;
			if(!v[j])dist[j]=min(dist[j],dist[x]+po);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
		//(0,i)->(?,i)==wi ?<=n
		//(i,j)->j*m+i;
		for(int j=1;j<=n;++j){
			mp[i*m+0].push_back({i*m+j,w[i]});
			mp[i*m+j].push_back({i*m+0,w[i]});
		}
	}
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		//(i,j)i line j station
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		for(int j=1;j<=k;++j){
			cin>>a[j]>>t[j];
				/*mp[a[j]*m+i].push_back({a[j-1]*m+i,0});
				mp[a[j-1]*m+i].push_back({a[j]*m+i,0});*/
			//(i,0)station center->(i,a)needs t
			mp[i].push_back({a[j]*m+i,t[j]});
			mp[a[j]*m+i].push_back({i,t[j]});
		}
	}
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		//(0,x)->(0,y)
		dj(x*m);
		cout<<dist[y*m]<<'\n';
	}
	/*for(int i=1;i<=m*m+m;++i){
		cout<<i<<" ";
		for(auto ed:mp[i]){
			cout<<ed.w<<" "<<ed.v<<" ";
		}
		cout<<'\n';
	}*/
	return 0;
}