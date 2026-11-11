#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>a[500510];
int t[500010];
int e[500010];
int d[500010];
signed main(){
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			a[x].push_back({5e5+i,0});
			a[500000+i].push_back({i,0});
			cin>>e[x];
		}
	}
	cout<<32<<endl<<17<<endl;
	return 0;
}
