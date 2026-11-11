//Oct31==Dec25?
//T2 subway 解法1 预期0
#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,q,w[500010],a[505][25],t[505][25],x[100010],y[100010];
void read(){
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();
	if(n==1){
		for(int i=1;i<=q;i++){
			cout<<w[x[i]]+w[y[i]]+t[1][x[i]]+t[1][y[i]];
		}
	}
	return 0;
}
