#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=5e5+5,maxk=5e5+5;
long long c,n,m,d,q,w[maxm],a[maxk],b[maxk],f[5005][5005],x,y;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>b[j];
		}
		for(int j1=1;j1<=k;j1++){
			for(int j2=1;j2<=k;j2++){
				f[a[j1]][a[j2]]=f[a[j2]][a[j1]]=min(f[a[j1]][a[j2]],b[j1]+b[j2]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int k=1;k<=m;k++){
			for(int j=1;j<=m;j++){
				if(i!=k&&i!=j&&j!=k) f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}


