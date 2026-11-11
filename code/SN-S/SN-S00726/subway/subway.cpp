#include<bits/stdc++.h>
using namespace std;
long long c,n,m,q,d,w[100010],a[3010][3010],t[3010][3010];
long long e[3010][3010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(e,0x3f,sizeof e);
	for(int rp=1;rp<=m;rp++)cin>>w[rp];
	for(int rp=1;rp<=n;rp++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[rp][j]>>t[rp][j];
			e[a[rp][j]][rp+m]=t[rp][j];
			e[rp+m][a[rp][j]]=t[rp][j];
		}
	}
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			for(int k=1;k<=m+n;k++){
				e[j][k]=min(e[j][k],e[j][i]+e[i][k]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<e[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
} 
