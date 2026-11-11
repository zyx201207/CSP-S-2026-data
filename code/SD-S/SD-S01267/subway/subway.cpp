#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define ROF(i,r,l) for(int i=r;i>=l;i--)
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define int long long 
#define fi first
#define se second
#define all(x) x.begin(),x.end()
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-48;
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int N = 5e5+10,inf=0x3f3f3f3f3f3f3f3f,NN=505;
typedef pair<int,int> pii;
int dis[NN][NN],w[N];
vector<pii> vc[N]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	FOR(i,1,m)w[i]=read();
	FOR(i,1,n){
		int k=read();
		while(k--){
			int x=read(),t=read();
			vc[x].push_back({i,t});
		}
	}
	FOR(i,1,n)FOR(j,1,n)dis[i][j]=inf;
	FOR(i,1,n)dis[i][i]=0;
	FOR(i,1,m){
		for(auto p:vc[i])for(auto q:vc[i])cmin(dis[p.fi][q.fi],p.se+q.se);
	}
	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)cmin(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x=read(),y=read(),ans=inf;
		for(auto j:vc[x])for(auto k:vc[y]){
			cmin(ans,dis[j.fi][k.fi]+j.se+k.se);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

