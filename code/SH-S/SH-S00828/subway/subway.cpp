#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSPS cout.tie(0);
int c,n,m,d,q,w[1145],k[1145],qk[1145],x,y,a[545][545],t[545][545],dist[545][545];
inline int floyd(){
	for(int k=1;k<=qk[n]*n;k++){
		for(int i=1;i<=qk[n]*n;i++){
			for(int j=1;j<=qk[n]*n;j++){
				dist[i][j]=max(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
signed main(){
	I AK CSPS
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		qk[i]+=k[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int i2=1;i2<=n;i2++){
				for(int j2=1;j2<=k[i2];j2++){
					if(i==i2&&j==j2) continue;
					dist[i*qk[i]+j][i2*qk[i2]+j2]=t[i][j]+t[i2][j2];
				}
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<dist[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
