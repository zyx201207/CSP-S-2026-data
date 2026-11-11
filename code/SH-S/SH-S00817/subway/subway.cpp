#include<bits/stdc++.h>
using namespace std;
int c,ans=0,n,m,d,q,w[500005],k[505],a[20005][505],t[20005][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++)ans+=a[i][j];
		}
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<endl;
	}
	return 0;
}
