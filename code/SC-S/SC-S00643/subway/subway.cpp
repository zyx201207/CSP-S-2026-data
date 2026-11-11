#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool mbs;
const int maxn=5e5+20;
const int maxm=520;
#define ll long long
ll fw,n,m,d,q,w[maxn],dis[maxm][maxm];
struct node{ll x,t;};
vector<node> a[maxn];
vector<int> e[maxm];
bool mbt;
int main(){
//	cerr<<(&mbs-&mbt)/1024.0/1024.0<<endl;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fw=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,k,x,y;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++) x=read(),y=read(),a[x].push_back({i,y}),e[i].push_back(x);
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int x:e[i]){
			ll k=0;
			for(auto now:a[x]) if(now.x==i) k=now.t;
			for(auto now:a[x]) dis[i][now.x]=min(dis[i][now.x],k+now.t);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int x,y;
	while(q--){
		ll ans=1e18;
		x=read(),y=read();
		for(auto nowx:a[x]) for(auto nowy:a[y]) ans=min(ans,w[x]+nowx.t+dis[nowx.x][nowy.x]+nowy.t+w[y]);
		printf("%lld\n",ans); 
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/