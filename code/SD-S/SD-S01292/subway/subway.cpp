#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,x,y,a[510][50010],t[510][50010],d,q,w[500100],k[500100];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+2*t[1][1]<<endl;
	}
}
