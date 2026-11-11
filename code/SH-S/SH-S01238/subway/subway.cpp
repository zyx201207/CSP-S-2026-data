#include<bits/stdc++.h>

using namespace std;

ifstream fin("subway.in");
ofstream fout("subway.out");
#define cin fin
#define cout fout
#define endl '\n'

using ll=long long;
const int N=5e2+9;
const int M=5e5+9;
const ll inf=1e18;

int c,n,m,o,q;
ll w[M],d[N][N];
vector<pair<int,ll>> p[M];

signed main(){
	cin>>c>>n>>m>>o>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		while(k--){
			int x;ll y;
			cin>>x>>y;
			p[x].push_back({i,y});
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) d[i][j]=(i==j?0:inf);
	}
	for(int i=1;i<=m;i++){
		for(auto s:p[i]){
			for(auto t:p[i]){
				d[s.first][t.first]=min(d[s.first][t.first],s.second+t.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}

	while(q--){
		int x,y;
		cin>>x>>y;
		
		ll ans=inf;
		for(auto i:p[x]){
			for(auto j:p[y]){
				ans=min(ans,d[i.first][j.first]+i.second+j.second);
			}
		}

		cout<<ans+w[x]+w[y]<<endl;
	}

	return 0;
}