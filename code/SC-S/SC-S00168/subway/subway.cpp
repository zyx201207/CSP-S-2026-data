#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
int l,r,c,n,m,d,q,w[M],a[N][25],k[N],t[N][25],ans;
int in[M],con[10005],o;
vector<pair<int,int>>g[10005];
int dij(int s,int e){
	int vis[100001],dis[100001];
	memset(dis,0x3f,sizeof dis);
	queue<int>q;
	dis[s]=0;
	q.push(s);
	while(q.size()){
		int x=q.front();
		q.pop();
		for(auto z:g[x]){
			int y=z.first;
			int c=z.second;
			if(dis[x]+c<dis[y]){
				dis[y]=dis[x]+c;
				q.push(y);
			}
		}
	}
	return dis[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			in[a[i][j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(in[i]){
			con[++o]=i;
			in[i]=o;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			g[in[a[i][j]]].push_back({o+i,t[i][j]});
			g[o+i].push_back({in[a[i][j]],t[i][j]});
		}
	}
	while(q--){
		cin>>l>>r;
		ans=w[l]+w[r];
		cout<<ans+dij(l,r)<<"\n";
	}
}