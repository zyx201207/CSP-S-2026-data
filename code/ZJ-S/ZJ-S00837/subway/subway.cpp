#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int w[N];
int a[501][1001],t[501][1001];
struct node{
	int nod,time;
};
vector<node> vec[501];
map<pair<int,int> ,int> mp;
vector<int> mapp[N];
signed main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			vec[a[i][j]].push_back({i,a[i][j]});
		}
		for(int j=2;j<=k;j++){
			vec[a[i][j]].push_back(a[i][j-1]);
			vec[a[i-1][j]].push_back(a[i][j]);
		}
	}
	while(q--){
		int first,end;
		cin>>first>>end;
		mp[{first,0}]=1;
		dfs();
		cout<<ans+w[first]+w[end]<<endl;
	}
	return 0;
}
//ll -> long long
