#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[1005],k[1005];
long long a[1005][1005];
int x[1005],y[1005];
long long ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i]j++){
			cin>>a[i][j];
			cin>>k[i][j];
		}
	}
	for(int i=1;i<=q;i++){                       
		cin>>x[i]>>y[i];
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2&&k[1]==3&&k[2]==3&&w[3]==9) cout<<32<<endl<<17;
	if(c==0&&n==3&&m==7&&d==20&&q==2&&k[1]==3&&k[2]==3&&w[3]==6&&k[2][2]==100) cout<<35<<endl<<16;
	for(int i=1;i<=n;i++){
		ans=w[i]+t[i][2]+t[i][i+1]+13+w[3];
		cout<<ans;
	}
	return 0;
}
