#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>
inline void read(T &a){
	a=0;char ch=getchar();
	while(ch < '0' || ch > '9')ch=getchar();
	while(ch >='0' && ch <='9')a=(a<<3)+(a<<1)+(ch^48),ch=getchar();
}
int w[500005];
int k[505];
vector<pair<int,int> >vec[500005];
int edge[505][505];
signed main(/*wow*/){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(edge,0x3f,sizeof(edge));
	int c,n,m,d,q;read(c);read(n);read(m);read(d);read(q);
	for(int i=1;i<=m;i++)read(w[i]);
	for(int i=1;i<=n;i++){
		read(k[i]);
		for(int j=1;j<=k[i];j++){
			int a,t;read(a);read(t);
			vec[a].push_back({i,t});
		}
		edge[i][i]=0;
	}
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++){
			for(int k=j+1;k<vec[i].size();k++){
				int x=vec[i][j].first,y=vec[i][k].first;
				edge[x][y]=min(edge[y][x],vec[i][j].second+vec[i][k].second);
				edge[y][x]=min(edge[y][x],vec[i][j].second+vec[i][k].second);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
			}
		}
	}
	while(q--){
		int x,y;read(x);read(y);
		int ans=0x3f3f3f3f3f3f3f3f;
		for(pair<int,int> i:vec[x]){
			for(pair<int,int> j:vec[y]){
				ans=min(ans,i.second+j.second+edge[i.first][j.first]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
}
