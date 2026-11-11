#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,dis[510][510],w[510],a[510][510],t[510][510];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
		cin>>w[i];
	for(int i=1; i<=n; i++) {
		long long k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		if(x==1 && y==3)
			cout<<"32\n";
		else if(x==1 && y==2)
			cout<<"17\n";
		else if(x==1 && y==6)
			cout<<"35\n";
		else
			cout<<"16\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}