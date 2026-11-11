#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[50002],a[1001][1001],t[1001][1001],x[100001],y[100001],ans[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			ans[i]+=a[i][j]+t[i][j];
		}
		ans[i]+=k;
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
	}
	return 0;
}