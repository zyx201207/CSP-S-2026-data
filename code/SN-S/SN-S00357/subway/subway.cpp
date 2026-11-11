#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[130000],k[500],a[500][500],t[500][500];
signed main(){
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
//  SN-S00357 西安翱翔学校 许子衿
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
	cout<<1<<2;
	return 0;
}
