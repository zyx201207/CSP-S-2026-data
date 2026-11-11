//十年OI一场空，不开long long见祖宗
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,x,y,a[505],fl[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n+m;i++)
		for(int j=1;j<=n+m;j++)
			if(i!=j)fl[i][j]=2e18;
	for(int i=1;i<=n;i++){
		ll k1,k2,k3;
		cin>>k1;
		for(int j=1;j<=k1;j++){
			cin>>k2>>k3;
			fl[i+m][k2]=k3;
			fl[k2][i+m]=k3;
		}
	}
	for(int k=1;k<=n+m;k++)
		for(int i=1;i<=n+m;i++)
			for(int j=1;j<=n+m;j++)
				fl[i][j]=min(fl[i][j],fl[i][k]+fl[j][k]);
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<a[x]+a[y]+fl[x][y]<<endl;
	}
	return 0;
}
/*
T2这么难吗………………本！！！
*/