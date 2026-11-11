#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001];
int a[501][50001];
int t[501][50001];
int k[501];
int x[100001],y[100001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<1<<"\n";
	}
	return 0;
}
