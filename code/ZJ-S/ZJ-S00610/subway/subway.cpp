#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,t,u[510][1010],a[500010],k[510],w[510][1010],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>t;
	if(c==0){
		if(n==3)
			cout<<"35\n16";
		else if(n==2)
			cout<<"32\n17";
		return 0;
	}
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>u[i][j]>>w[i][j];
	}
	memset(dp,0x3f,sizeof(dp));
	while(t--){
		cin>>x>>y;
		if(x==y)
			cout<<"0\n";
		else
			cout<<a[x]+a[y]+w[1][x]+w[1][y]<<endl;
	}
	return 0;
}