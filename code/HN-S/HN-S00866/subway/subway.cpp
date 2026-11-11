#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[510],a[510][50010],t[510][50010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int t=w[x]+w[y];
		cout<<t;
	}
	return 0;
}

