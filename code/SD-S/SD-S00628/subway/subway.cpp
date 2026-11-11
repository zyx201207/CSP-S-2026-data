#include<bits/stdc++.h>
using namespace std;

#define F(i,s,e) for(int i=s;i<=e;i++)
const int N = 505,M = 5e5+10;
using ll = long long;
ll w[M],k[N];
ll dis[N][N];
vector<ll>g[M];
inline int rd(){
	int n=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') n=n*10+c-'0',c=getchar();
	return n*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	memset(dis,0x3f,sizeof dis);
	F(i,1,m)w[i]=rd();
	F(i,1,n){
		dis[i][i]=0;
		k[i]=rd();
		F(j,1,k[i]){
			int a=rd(),t=rd();
			g[a].push_back(((ll)t<<10ll)+i);
		}
	}
	F(i,1,m){
		F(j,0,g[i].size()-1){
			F(k,j+1,g[i].size()-1){
				ll x=g[i][j]&1023,y=g[i][k]&1023;
//				cout<<x<<' '<<y<<'\n';
				dis[x][y]=dis[y][x]=min(dis[x][y],(g[i][j]>>10)+(g[i][k]>>10));
//				cout<<dis[1][2]<<'\n';
			}
		}
	}
	F(k,1,n)
		F(i,1,n)
			F(j,1,n)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x=rd(),y=rd();
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(ll u:g[x])
			for(ll v:g[y])
				ans=min(ans,dis[u&1023][v&1023]+(u>>10)+(v>>10));
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
