#include<bits/stdc++.h>
#define int long long
struct at{
	int dtz,tim;
}a[505][100005];
int w[500005];
signed main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[i][j].dtz>>a[i][j].tim;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	return 0;
}
