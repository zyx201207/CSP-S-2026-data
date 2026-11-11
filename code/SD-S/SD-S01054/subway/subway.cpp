#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll read();
int c,n,m,d,q;
ll dis[505][505],w[N],k[505];
vector<int> a[505],t[505];
struct Sub{
	int to,w,id;
};vector<Sub>g[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=0;j<k[i];j++){
			int na=read(),nt=read();
			a[i].push_back(na),t[i].push_back(nt);
			g[na].push_back({i,nt,j});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int h=1;h<=m;h++){
		int len=g[h].size();
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				ll u=g[h][i].to,v=g[h][j].to,tu=g[h][i].w,tv=g[h][j].w;
				dis[u][v]=dis[v][u]=min(dis[u][v],tu+tv);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||j==k||i==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}cout<<'\n';
//	}
//	cout<<'!';
	while(q--){
		int l=read(),r=read();
		ll mn=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<g[l].size();i++){
			for(int j=0;j<g[r].size();j++){
				ll u=g[l][i].to,v=g[r][j].to;
				int uid=g[l][i].id,vid=g[r][j].id;
//				cout<<u<<' '<<v<<' '<<uid<<' '<<vid<<' '<<'\n';
//				cout<<t[u][uid]<<' '<<t[v][vid]<<' '<<dis[u][v]<<'\n';
				mn=min(mn,t[u][uid]+t[v][vid]+dis[u][v]);
			}
		}cout<<mn+w[l]+w[r]<<'\n';
	}
	return 0;
}
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}


