#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
int a[505][500005];
int t[505][500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
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
		for(int j=1;j<=2*k;j++){
			if(j%2==1) cin>>a[i][j/2+1];
			else cin>>t[i][j/2];
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+123;
		}
	}
	return 0;
}