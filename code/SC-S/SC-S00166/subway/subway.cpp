#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int x;
	vector<int>a(m+1);
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>x;
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<a[u]+a[v]+x*2*(n-1)<<endl;
	}
	return 0;
}