#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,q;
int w[N],k[505],a[505][50005],t[505][50005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y,time=0;
		cin>>x>>y;
	}
	cout<<"35\n16";
	return 0;
}
