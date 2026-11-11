#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pli=pair<ll,int>;
const int MAXN=10905;
vector<int> w(MAXN);
vector<pli> g[MAXN];
int c,n,m,d,q;
vector<vector<ll> > minx(MAXN,vector<ll>(MAXN,-1));

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			minx[t][i+n]=minx[i+n][t]=a;
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		if(minx[x][y]<0)
		cout<<minx[x][1+n]+minx[y][1+n]+w[x]+w[y]<<endl;
	}
	return 0;
}
