#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10005
int n,m;
int dis[N][N];
vector<int> st;
struct Edge{
	int f;
	int t;
};
int fa[N];
int find(int u){
	if(fa[u]==u){
		return u;
	}
	fa[u]=find(fa[u]);
	return fa[u];
}
vector<Edge> edge;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int ccc,T;
	cin>>ccc>>T;
	while(T--){
		memset(dis,0x3f,sizeof(dis));
		cin>>n>>m;
		int ans=1e9;
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			fa[i]=i;
		}
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			dis[u][v]=min(dis[u][v],(long long)1);
			dis[v][u]=min(dis[v][u],(long long)1);
			Edge s;
			s.f=u;
			s.t=v;
			edge.push_back(s);
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		int qj=(1<<n)-1;
		for(int s=0;s<=qj;s++){
			for(int i=1;i<=n;i++){
				fa[i]=i;
				if((s>>(i-1))&1){
					st.push_back(i);
				}
			}
			if(st.size()!=m){
				while(!st.empty()){
					st.pop_back();
				}
				continue;
			}
			for(Edge u:edge){
				int f=u.f;
				int t=u.t;
				if(!((s>>(f-1))&1)){
					continue;
				}
				if(!((s>>(t-1))&1)){
					continue;
				}
				f=find(f);
				t=find(t);
				if(f==t){
					continue;
				}
				fa[f]=t;
			}
			int cc=0;
			for(int i:st){
				if(fa[i]==i){
					cc++;
				}
			}
			if(cc>2){
				while(!st.empty()){
					st.pop_back();
				}
				continue;
			}
			int ra=-1;
			for(int i=1;i<=n;i++){
				int kk=1e9;
				for(int j:st){
					kk=min(kk,dis[i][j]);
				}
				ra=max(ra,kk);
			}
			ans=min(ans,ra);
			while(!st.empty()){
				st.pop_back();
			}
		}
		cout<<ans<<'\n';
		while(!edge.empty()){
			edge.pop_back();
		}
	}
	return 0;
}
