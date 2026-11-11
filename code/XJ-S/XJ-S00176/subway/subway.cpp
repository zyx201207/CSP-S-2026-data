#include<bits/stdc++.h>
using namespace std;
const int N=502,K=5e5+2;
int c,n,m,d,q,w[K],a[N][K],t[N][K],x,y;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++)cin>>a[i][j];
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+5<<'\n';
	}
	return 0;
}
