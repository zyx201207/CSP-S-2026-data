#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > a(501),t(501);
vector<vector<int> > g(10086,vector<int>(10086,-1));
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q; 
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);//各地铁口走到站厅的距离
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		g[i][i]=0;
		int k;
		cin>>k;
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+t[x][x]+t[x][y]+w[y]<<endl;
	}
	return 0;
}
