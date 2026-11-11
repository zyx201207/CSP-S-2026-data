#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10,M=5e5+10;
int n,c,m,d,q,w[M];
unordered_map<int,int>co[M];
inline int read(){
	char c=getchar();
	int u=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		u=u*10+c-'0';
		c=getchar();
	}
	return u*f;
}
int dis[N][N];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	memset(dis,0x3f,sizeof dis);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1; i<=n; i++)dis[i][i]=0;
	for(int i=1; i<=m; i++) {
		w[i]=read();
	}
	int k,a,t;
	for(int i=1; i<=n; i++) {
		k=read();
		for(int j=1; j<=k; j++) {
			a=read(),t=read();
			for(pair<int,int> p:co[a]) {
				dis[i][p.first]=dis[p.first][i]=min(dis[i][p.first],1ll*p.second+1ll*t);
			}
			co[a][i]=t;
		}

	}
//	for(int i=1;i<=m;i++){
//		for(pair<int,int> p1:co[i]){
//			for(pair<int,int){
//				if(p1.f==p2.f)
//				con;
//				dis[p1.first][p2.first]=dis[p2.first][p1.first]=min(dis[p1.first][p2.first],);
//			}
//		}
//	}
	for(int l=1; l<=n; l++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
			}
		}
	}
	int x,y;
	while(q--) {
		x=read(),y=read();
		int ans=0x3f3f3f3f3f;
		for(pair<int,int> _x:co[x]) {
			for(pair<int,int> _y:co[y]) {
				ans=min(ans,dis[_x.first][_y.first]+w[x]+w[y]+_x.second+_y.second);
			}
		}
		cout<<ans<<'\n';
	}
//	if(a[i]*(i-mid+1))
	return 0;
}
