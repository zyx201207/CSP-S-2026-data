#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[505][5005];
int t[505][5005];
int w[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while (q--){
		int s,e;
		cin>>s>>e;
	}
	return 0;
}