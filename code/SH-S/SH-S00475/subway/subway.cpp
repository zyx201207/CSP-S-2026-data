#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[510],k,t[510][510],z[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>z[510]>>t[i][j];
			t[j][i]=t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int sum=w[x]+w[y]+t[x][y]+t[x][x];
		cout<<sum<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
