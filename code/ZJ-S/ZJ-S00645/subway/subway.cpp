#include<iostream>
#include<cstring>
#define F(i,k,n) for(int i=(k);i<=(n);++i)
#define RF(i,n,k) for(int i=(n);i>=(k);--i)
#define LL long long
using namespace std;
LL dis[505][505];
int t[500005];
int s[500005][25];
int h[500005][25];
int tot[500005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _,n,m,d,q;
	cin>>_>>n>>m>>d>>q;
	F(i,1,m){
		cin>>t[i];
	}
	F(i,1,n){
		int z;
		cin>>z;
		while(z--){
			int u,v;
			cin>>u>>v;
			++tot[u];
			s[u][tot[u]]=i;
			h[u][tot[u]]=v;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	F(i,1,m){
		F(j,1,tot[i]){
			//cout<<"i="<<i<<" u="<<s[i][j]<<'\n';
			F(k,j+1,tot[i]){
				dis[s[i][k]][s[i][j]]=dis[s[i][j]][s[i][k]]
				=min(dis[s[i][j]][s[i][k]],(LL)h[i][j]+h[i][k]);
				//cout<<i<<' '<<s[i][j]<<' '<<s[i][k]<<' '<<h[i][j]+h[i][k]<<'\n';
			}
		}
	}
	F(i,1,n){
		dis[i][i]=0;
	}
	F(k,1,n){
		F(i,1,n){
			F(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		LL ans=4e18;
		F(i,1,tot[u]){
			F(j,1,tot[v]){
				ans=min(ans,dis[s[u][i]][s[v][j]]+h[u][i]+h[v][j]);
			}
		}
		cout<<ans+t[u]+t[v]<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

92-100pts
*/