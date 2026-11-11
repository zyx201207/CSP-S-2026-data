#include <bits/stdc++.h>
#define ll long long
using namespace std;
int rin(){
	int x=0,t=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*t;
}
ll rll(){
	ll x=0,t=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*t;
}
const int M=5e5;
int C,n,m,d,q;
ll w[M];
vector<pair<int,ll> > a[M];
ll b[510][510];
pair<int,int> c[100010];
void solve(int i){
	int u=c[i].first,v=c[i].second;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > qq;
	for(int j=0;j<a[u].size();j++){
		b[n+1][a[u][j].first]=w[u]+a[u][j].second;
		qq.push({w[u]+a[u][j].second,a[u][j].first});
	}
	for(int j=0;j<a[v].size();j++){
		b[a[v][j].first][n+2]=w[v]+a[v][j].second;
	}
//	for(int ii=1;ii<=n+2;ii++){
//		for(int jj=1;jj<=n+2;jj++){
//			cout<<b[ii][jj]<<' ';
//		}
//		cout<<endl;
//	}
	vector<bool> z(n+10,0);
	while(!qq.empty()){
		pair<ll,int> x=qq.top();qq.pop();
		if(x.second==n+2){
			printf("%lld\n",x.first+b[x.second][n+2]);
			return;
		}
		if(z[x.second])continue;
		z[x.second]=1;
		for(int yy=1;yy<=n+2;yy++){
			if(b[x.second][yy]!=0){
				if(z[yy])continue;
				qq.push({x.first+b[x.second][yy],yy});
			}
		}
	}
	for(int j=0;j<=n+2;j++){
		b[n+1][j]=0;
	}
	for(int j=0;j<=n+2;j++){
		b[j][n+2]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=rin();n=rin();m=rin();d=rin();q=rin();
	for(int i=1;i<=m;i++)w[i]=rll();
	for(int i=1;i<=n;i++){
		int k=rin();
		for(int j=1;j<=k;j++){
			int x=rin();
			ll y=rll();
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=q;i++){
		int x=rin(),y=rin();
		c[i]={x,y};
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			int u=a[i][j].first;
			for(int k=j+1;k<a[i].size();k++){
				int v=a[i][k].first;
				if(!b[u][v])b[u][v]=a[i][j].second+a[i][k].second;
				b[u][v]=min(b[u][v],a[i][j].second+a[i][k].second);
				b[v][u]=b[u][v];
			}
		}
	}
	for(int i=1;i<=q;i++){
		solve(i);
	}
	return 0;
}