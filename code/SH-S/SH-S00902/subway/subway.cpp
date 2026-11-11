#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[50007];
int k[507];
int a[50000][507];
int t[50000][507];
int x[10007];
int y[10007];
int ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int ans=0;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ans+=t[i][j];
		}
		cout<<ans<<endl;
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	return 0;
}

