#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
vector<pair<int,int>>g[N*21];
int a[N],t[N];
long long dist[N*21];
int cnt[N];
void dij(int s){
	memset(dist,0x3f,sizeof dist);
	dist[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,s});
	int u,dian;
	long long l,d;
	while(!q.empty()){
		u=q.top().second,l=q.top().first;
		q.pop();
		if(dist[u]!=l)continue;
		for(auto i:g[u]){
			dian=i.first,d=i.second;
			if(dist[dian]>l+d){
				dist[dian]=l+d;
				q.push({l+d,dian});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			cnt[a[j]]++;
			g[a[j]].push_back({a[j]+cnt[a[j]]*m,t[j]});
			g[a[j]+cnt[a[j]]*m].push_back({a[j],t[j]});
			if(j>1){
				g[a[j-1]+cnt[a[j-1]]*m].push_back({a[j]+cnt[a[j]]*m,0});
				g[a[j]+cnt[a[j]]*m].push_back({a[j-1]+cnt[a[j-1]]*m,0});
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		dij(x);
		cout<<w[x]+w[y]+dist[y]<<'\n';
	}
	return 0;
}
