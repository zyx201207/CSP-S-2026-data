#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+5;
LL c,n,m,d,q,a[N],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		LL g[k][k],h[k][k];
		for(int j=1;j<=k;j++){
			cin>>g[i][j]>>h[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<ans;
	return 0;
} 
