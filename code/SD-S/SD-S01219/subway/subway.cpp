#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
#define psb push_back
 
const int N=550,M=5e5+1000;
const int inf=1e17;
int c,n,m,d,q;
int w[M];
int e[N][N];
int ntt;
vector<pii >vec[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	system("fc subway7.ans subway.out");return 0;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) e[i][j]=inf;
		e[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;cin>>x>>t;
			for(pii p:vec[x]){
				int y=p.F,z=p.S;
				e[i][y]=min(e[i][y],t+z);
				e[y][i]=min(e[y][i],t+z);
			}vec[x].psb(mkp(i,t));
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k) continue;
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	for(int tms=1;tms<=q;tms++){
		int st,ed;
		cin>>st>>ed;
		int minn=inf;
		for(pii px:vec[st]){
			for(pii py:vec[ed]){
				minn=min(minn,px.S+py.S+e[px.F][py.F]);	
			}
		}cout<<minn+w[st]+w[ed]<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
