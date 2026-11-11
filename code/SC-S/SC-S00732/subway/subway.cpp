#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
using namespace std;
const int M=5e5+5,N=505;
const ll inf=(1ll<<60);
int c,m,n,d,q;
int w[M];
vector<int>sub[M];//经过该点地铁
map<int,int>x[N];//地铁到站厅距离
ll f[N][N]; 
inline int read(){
	int x=0;
	char c=getchar();
	while(c>='0'||c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
inline void write(const ll &x){
	if(x<10){
		putchar('0'+x);
		return;
	}
	write(x/10);
	putchar('0'+x%10);
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	rep(i,1,m)
		w[i]=read();
	rep(i,1,n){
		int k=read();
		rep(j,1,k){
			int v=read(),val=read();
			x[i][v]=val;
			sub[v].push_back(i);
		}
	}
	rep(i,1,n)
		rep(j,1,n)
			f[i][j]=inf;
	rep(i,1,m){
		if(sub[i].size()<=1)continue;
		int lim=(int)sub[i].size()-1;
		rep(j,1,lim)
			rep(k,0,j-1){
				int u=sub[i][j],v=sub[i][k];
				//cout << "test: " << u << " -> " << v << " : " << x[u][i] + x[v][i] << '\n';
				f[u][v]=f[v][u]=min(f[u][v], 1ll*x[u][i] + x[v][i] );
			}
	}
	
	rep(i,1,n)
		f[i][i]=0;
	/*
	rep(i,1,n){
		rep(j,1,n)
			cout << f[i][j] << ' ';
		cout << '\n';
	}
	*/
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	//cout << "test:" << f[1][2] << '\n';
	
	while(q--){
		int s,t;cin >> s >> t;
		ll ans=w[s]+w[t];
		ll cur=inf;
		int lim1=(int)sub[s].size()-1;
		int lim2=(int)sub[t].size()-1;
		rep(i,0,lim1)
			rep(j,0,lim2){
				int u=sub[s][i],v=sub[t][j];
				ll z=f[ u ][ v ];
				cur=min(cur,z + x[u][s] + x[v][t] );
			}
		write(ans+cur);
	}
	
	return 0;
}