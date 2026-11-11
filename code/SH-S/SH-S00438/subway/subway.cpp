#include<bits/stdc++.h>
using namespace std;
const int maxn=5000;
int c,n,d,m,q,w[maxn],k[maxn],a[maxn][maxn],t[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<t[x][y]<<endl;
	}
	return 0;
}
