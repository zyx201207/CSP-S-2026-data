#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[500005],k[505],a[5005][5005],t[5005][5005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
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
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		long long ans=w[x]+w[y]+t[i][y]+t[i][x];
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
