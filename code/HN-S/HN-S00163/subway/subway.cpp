#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1],k[n+1],a[n+1][500005],t[n+1][500005],x,y,num[m+1]={0};

	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		int ans=0;
		ans=ans+w[x]+w[y]+t[x][y];
		cout<<ans<<"\n";
	}
	return 0;
} 
