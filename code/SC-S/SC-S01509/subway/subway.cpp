#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const int N=550,M=5e5+100;
ll dis[N][N];int w[M],c,n,m,d,q;ll ans;
vector<pair<int,int>>g[M];
int qread(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	c=qread(),n=qread(),m=qread(),d=qread(),q=qread();
	for(int i=1;i<=m;i++)w[i]=qread();
	for(int i=1,k;i<=n;i++){
		k=qread();
		for(int j=1,aa,tt;j<=k;j++){
			aa=qread(),tt=qread();
			g[aa].push_back({i,tt});
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(pair<int,int>e:g[i]){
			for(pair<int,int>f:g[i]){
				dis[e.first][f.first]=min(dis[e.first][f.first],(ll)e.second+f.second);
				dis[e.first][f.first]=min(dis[e.first][f.first],(ll)e.second+f.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x=qread(),y=qread();ans=inf;
		for(pair<int,int>e:g[x]){
			for(pair<int,int>f:g[y]){
				ans=min(ans,dis[e.first][f.first]+e.second+f.second);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}