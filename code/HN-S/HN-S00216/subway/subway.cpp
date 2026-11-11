#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=505;
const int M=5e5+5;
const ll inf=1e17;

int c,n,m,d,q;
ll g[N][N];
ll t[M];
vector<int>a[M];
vector<ll>b[M];
ll ans;

inline ll read(){
	char c;
	int f=1;
	ll res=0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
		  f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res*=10;
		res+=(c-'0');
		c=getchar();
	}
	return res*f;
}

inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	  write(x/10);
	putchar((x%10)+'0');
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  	g[i][j]=inf;
	for(int i=1;i<=m;i++)
	  t[i]=read();
	ll k,u,e,v;
	for(int i=1;i<=n;i++){
		g[i][i]=0;
		k=read();
		for(int j=1;j<=k;j++){
			u=read(),e=read();
			a[u].push_back(i);
			b[u].push_back(e);
		}
	}
	/*
	for(int i=1;i<=m;i++){
		cout<<i<<":\n";
		for(int j=0;j<a[i].size();j++)
		  cout<<a[i][j]<<' '<<b[i][j]<<'\n';
	}
	*/
	for(int i=1;i<=m;i++){
		for(u=0;u<(int)a[i].size();u++){
			for(v=u+1;v<(int)a[i].size();v++){
				if(b[i][u]+b[i][v]<g[a[i][u]][a[i][v]]){
					g[a[i][u]][a[i][v]]=b[i][u]+b[i][v];
					g[a[i][v]][a[i][u]]=b[i][u]+b[i][v];
//					cout<<a[i][u]<<' '<<a[i][v]<<':'<<b[i][u]+b[i][v]<<'\n';
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(g[i][k]+g[k][j]<g[i][j]){
					g[i][j]=g[i][k]+g[k][j];
					g[j][i]=g[i][k]+g[k][j];
				}
			}
		}
	  	
	}
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		ans=inf;
		for(int uu=0;uu<(int)a[u].size();uu++){
			for(int vv=0;vv<(int)a[v].size();vv++){
//				cout<<t[u]<<' '<<t[v]<<' '<<a[u][uu]<<' '<<a[v][vv]<<": "<<g[a[u][uu]][a[v][vv]]<<'\n';
				ans=min(ans,g[a[u][uu]][a[v][vv]]+t[u]+t[v]+b[u][uu]+b[v][vv]);
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
