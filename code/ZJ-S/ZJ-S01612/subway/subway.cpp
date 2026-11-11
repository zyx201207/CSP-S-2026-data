#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5,D=21;
int _,n,m,d,q,k[N],v[M];
int a[N][D],vis[M][D];
ll w[M],dis[N][N];
struct Line{
	int id;
	ll t;
}L[N][D];
bool cmp(Line a,Line b){
	return a.id<b.id;
}
int query(int x,int p){
	int l=1,r=k[x];
	while(l<r){
		int mid=l+r+1>>1;
		if(L[x][mid].id<=p)l=mid;
		else r=mid-1;
	}
	return l;
}
void bfs(int p){
	dis[p][p]=0;
	queue<int>q;
	q.push(p);
	while(!q.empty()){
		int fr=q.front();q.pop();
		for(int i=1;i<=k[fr];++i){
			int x=L[fr][i].id;
			for(int j=1;j<=v[x];++j){
				int to=vis[x][j];
				if(to==fr)continue;
				ll s=L[fr][i].t+L[to][query(to,x)].t;
				if(dis[p][fr]+s<dis[p][to]){
					q.push(to);
					dis[p][to]=dis[p][fr]+s; 
				}
			}
		}
	}
	return;
}
void solve(){
	int l,r;cin>>l>>r;
	ll ans=0x7f7f7f7f7f7f7f7f;
	for(int i=1;i<=v[l];++i){
		for(int j=1;j<=v[r];++j){
			int x=vis[l][i],y=vis[r][j];
			ans=min(ans,L[x][query(x,l)].t+dis[x][y]+L[y][query(y,r)].t);
		}
	}
	cout<<w[l]+w[r]+ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j)
			cin>>L[i][j].id>>L[i][j].t;
		sort(L[i]+1,L[i]+k[i]+1,cmp);
		for(int j=1;j<=k[i];++j)
			vis[L[i][j].id][++v[L[i][j].id]]=i;
	}
	for(int i=1;i<=n;++i)bfs(i);
	while(q--)solve();
	return 0;
}
