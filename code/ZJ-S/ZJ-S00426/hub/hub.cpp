#include<bits/stdc++.h>
using namespace std;
const int N=5005+6;
int n,k,c,t;
vector<int>e[N];
int dep[N],d[N];
int fa[N],rt,a[N];
int st1[21][N];
int st2[21][N];
int st3[21][N];
int flag[N];
int cnt[5005][5005];
int get1(int x,int y) {
	if(y<x)return -1e9;
	int tmp = __lg(y-x+1);
	return max(st1[tmp][x],st1[tmp][y-(1<<tmp)+1]);
}

int get2(int x,int y) {
	if(y<x)return -1e9;
	int tmp = __lg(y-x+1);
	return max(st2[tmp][x],st2[tmp][y-(1<<tmp)+1]);
}
int get3(int x,int y) {
	if(y<x)return -1e9;
	int tmp = __lg(y-x+1);
	return max(st3[tmp][x],st3[tmp][y-(1<<tmp)+1]);
}
void dfs1(int u,int F) {
	dep[u] = dep[F]+1;
	fa[u] = F;
	if(dep[u] >dep[rt])rt=u;
	for(int v:e[u]) {
		if(v==F)continue;
		dfs1(v,u);
	}
}
int dsu[N];
int find(int x) {
	return dsu[x]==x?x:dsu[x]=find(dsu[x]);
}
void merge(int x,int y) {
	x=find(x);
	y=find(y);
	if(x==y)return ;
	dsu[x]=y;
}
int b[N],tot,mx;
int dis[N];
int Cnt[1<<12];
bitset<N>bit[N];
void dfs3(int u,int F,int d,int mid,int rt){
	bit[rt][u] = 1;
	for(int v:e[u]){
		if(d+1 > mid)continue;
		if(u==F)continue;
		dfs3(v,u,d+1,mid,rt);
	}
}
bool check(int mid) {

	for(int i=1; i<=n; i++) {
		bit[i].reset();
		bit[i][i] =1;
	}
	for(int i=1;i<=n;i++){
		dfs3(i,0,0,mid,i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((bit[i] | bit[j]).count()==n){
				return true;
			}
		}
	}
	return false;
	
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	cin>>c>>t;
	while(t--) {
		tot=0;
		cin>>n>>k;
		for(int i=1; i<=n; i++)e[i].clear(),flag[i] = 0;
		for(int i=1,u,v; i<n; i++) {
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(k==2) {
			int l=0,r=n,ans=0;
			while(l<=r) {
				int mid=l+r>>1;
				if(check(mid))ans=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<ans<<endl;
			continue;
		}
		int ans=1e9;

		for(int st=1; st<(1<<n); st++) {
			Cnt[st] = Cnt[st/2] +(st&1);
			if(Cnt[st] > k)continue;
			for(int j=1; j<=n; j++)dsu[j] = j;
			int cnt=0;
			for(int i=1; i<=n; i++) {

				if(st&1<<i-1)for(int j:e[i]) {
						if(st&1<<j-1)merge(i,j);
					}
			}
			for(int i=1; i<=n; i++) {
				if(dsu[i] ==i && st&1<<(i-1))cnt++;
			}
			if(cnt>2)continue;
			for(int i=1; i<=n; i++)dis[i] = 1e9;
			queue<int>q;

			for(int i=1; i<=n; i++) {
				if(st&1<<i-1)dis[i]=0,q.push(i);
			}
			int mx=0;

			while(!q.empty()) {
				int u=q.front();
				q.pop();
				for(int v:e[u]) {
					if(dis[v] > dis[u]+1 ) {
						dis[v] = dis[u] +1;
						mx=max(mx,dis[v]);
						q.push(v);
					}
				}
			}
			//	cout<<cnt<<" "<<st<<" "<<mx<<endl;
			ans=min(ans,mx);
		}
		cout<<ans<<"\n";
	}

	return 0;
}