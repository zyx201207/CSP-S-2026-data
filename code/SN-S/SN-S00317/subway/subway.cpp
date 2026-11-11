#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int Maxm=5e5+5,Maxn=505,INF=1e18;
int id,n,m,d,q,x1,x2,x3,w[Maxm],f[Maxn][Maxn],ans;
vector<vector<pair<int,int>>> v;
void Add(int x1,int x2,int x3){
	f[x1][x2]=min(f[x1][x2],x3);
	f[x2][x1]=min(f[x2][x1],x3);
//	cout<<x1<<' '<<x2<<' '<<x3<<'\n';
}
void Floyd(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int h=1; h<=n; h++){
				if(f[j][h]>f[j][i]+f[i][h]){
					f[j][h]=f[j][i]+f[i][h];
				}
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>id>>n>>m>>d>>q;
	v=vector<vector<pair<int,int>>>(m+5);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			f[i][j]=INF;
		}
	}
	for(int i=1; i<=n; i++)f[i][i]=0;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	for(int i=1; i<=n; i++){
		cin>>x1;
		for(int j=0; j<x1; j++){
			cin>>x2>>x3;
			v[x2].push_back({i,x3});
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=0; j<v[i].size(); j++){
			for(int h=j+1; h<v[i].size(); h++){
				Add(v[i][j].first,v[i][h].first,v[i][j].second+v[i][h].second);
			}
		}
	}
	Floyd();
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=n; j++){
//			cout<<f[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1; i<=q; i++){
		cin>>x1>>x2;
		ans=INF;
		for(int j=0; j<v[x1].size(); j++){
			for(int h=0; h<v[x2].size(); h++){
				ans=min(ans,w[x1]+w[x2]+v[x1][j].second+v[x2][h].second+f[v[x1][j].first][v[x2][h].first]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
longlong

×î¶ÌÂ·Floyd 
*/
