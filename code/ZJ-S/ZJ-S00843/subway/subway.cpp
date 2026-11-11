#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a,t;
struct node{
	int v,t;
};
vector<node>g[500005];
vector<int>gt[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			g[a].push_back({i,t});
			gt[i].push_back(a);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<'\n';
	}
	return 0;
}