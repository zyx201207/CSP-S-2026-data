#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N_min = 2e6+10;
const int N = 5e5+10;
int c,n,m,d,q;
int zkx,hcy;
int w_M[510];//door<->waiting
int a_M,t_M,k_M;//working<->waiting
int id_M[510],head_M[510],tot,dis_M[510][510];
bool vis_M[510];
struct lplp{
	int Next,ver,w;
}e_M[N_min];
void add_M(int x,int y,int w){
	++tot;
	e_M[tot].ver=y;
	e_M[tot].Next=head_M[x];
	e_M[tot].w=w;
	head_M[x]=tot;
}
struct node{
	int id,dis_M;
	bool operator <(const node &op)const{
		return dis_M<op.dis_M;
	}
};
void Dijkstra_M(int s){
	memset(vis_M,0,sizeof(vis_M));
	priority_queue<node> q;
	q.push({s,0});
	while(!q.empty()){
		int t=q.top().id;
		q.pop();
		for(int i=head_M[t];i;i=e_M[i].Next){
			int v=e_M[i].ver,w=e_M[i].w;
			if(dis_M[s][v]>dis_M[s][t]+w){
				dis_M[s][v]=dis_M[s][t]+w;
				if(!vis_M[v]) q.push({v,dis_M[s][v]});
			}
		}
	}
}
void Solve_MA(){
	for(int i=1;i<=m;++i) cin>>w_M[i];
	for(int i=1;i<=n;++i){
		memset(id_M,0,sizeof(id_M));
		cin>>k_M;
		for(int j=1;j<=k_M;++j){
			cin>>a_M>>t_M;
			id_M[a_M]=t_M;
		}
		for(int j=1;j<=m;++j){
			for(int l=1;l<=m;++l){
				if(j==l) continue;
				dis_M[j][l]=LLONG_MAX;
				if(id_M[j]&&id_M[l]){
					add_M(j,l,id_M[j]+id_M[l]);
					add_M(l,j,id_M[j]+id_M[l]);
				}
			}
		}
	}
	for(int i=1;i<=m;++i) Dijkstra_M(i);
	for(int i=1;i<=q;++i){
		cin>>zkx>>hcy;
		cout<<dis_M[zkx][hcy]+w_M[zkx]+w_M[hcy]<<'\n';
	}
}
int w[N],k,a,t,val[N][3];
void Solve_N(){
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>t;
			val[a][i]=t;
		}
	}
	int Tra=LLONG_MAX;
	for(int i=1;i<=m;++i){
		if(val[i][1]&&val[i][2])
			Tra=min(Tra,val[i][1]+val[i][2]);
	}
	for(int i=1;i<=q;++i){
		cin>>zkx>>hcy;
		int ans=LLONG_MAX;
		int V_z1=val[zkx][1],V_z2=val[zkx][2];
		int V_h1=val[hcy][1],V_h2=val[hcy][2];
		if(V_z1&&V_h1) ans=min(ans,V_z1+V_h1);
		if(V_z2&&V_h2) ans=min(ans,V_z2+V_h2);
		if(V_z1&&V_h2) ans=min(ans,V_z1+V_h2+Tra);
		if(V_z2&&V_h1) ans=min(ans,V_z2+V_h1+Tra);
		cout<<ans+w[zkx]+w[hcy]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c<=11) Solve_MA();
	else if(c>=20&&c<=21) Solve_N();
	return 0;
}