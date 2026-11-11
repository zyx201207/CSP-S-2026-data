#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010],k[500010],a[510][500010],t[510][500010];
vector<int>g[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cin>>a[i][1]>>t[i][1];
		for(int j=2;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
	}
	return 0;
}

