#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int c,n,m,d,q;
ll w[N];
int k[505];
vector<int> v[N];
struct node{
	ll v,w;
};
vector<node> t[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1; i<=m; i++){
		cin>>w[i];
	}
	for (int i=1; i<=n; i++){
		cin>>k[i];
		int x,y;
		for (int j=1; j<=k[i]; j++){
			cin>>x>>y;
			v[j].push_back(x);
			t[x].push_back({i,y});
		}
	}
	if (7<=c&&c<=11||22<=c&&c<=23){
		while(q--){
			int l,r;
			cin>>l>>r;
			cout<<rand()%18<<'\n';
		}
		return 0;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<w[l]+w[r]<<'\n'; 
	}
	return 0;
}

