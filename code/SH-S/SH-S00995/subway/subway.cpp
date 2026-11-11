#include<bits/stdc++.h>
#define int long
using namespace std;
const int N=5*1e5+9;
int n,c,m,d,q,y,ans=1e9,sum=0;
int w[N],t[509][N];
int n,d,c,t;
int a[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x;
		cin>>x>>y;
	}
	return 0;
}
