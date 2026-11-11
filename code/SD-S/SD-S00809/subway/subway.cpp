#include<bits/stdc++.h>
using namespace std;
int w[500010],k[510],a[510][50010],t[510][50010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			w[i]+=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		cout<<w[x]+w[y]+2*t[1][1]<<'\n';
	}
	return 0;
}
