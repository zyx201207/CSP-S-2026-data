#include<iostream>
#include<cstring>
using namespace std;
long long c,n,m,d,q,ans=0,W;
long long w[500050];
long long t[505][20050];
long long f[505][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1; i<=m; i++){
		cin>>w[i];
	}
	memset(t,0x3f,sizeof(t));
	for(long long i=1; i<=n; i++){
		long long sz;
		cin>>sz;
		for(long long j=1; j<=sz; j++){
			long long v,val;
			cin>>v>>val;
			t[i][v]=val;
		}
	}
	memset(f,0x3f,sizeof(f));
	for(long long i=1; i<=n; i++){
		f[i][i]=0;
		for(long long j=i+1; j<=n; j++){
			for(long long k=1; k<=m; k++){
				f[i][j]=f[j][i]=min(f[i][j],t[i][k]+t[j][k]);
			}
		}
	}
	for(long long k=1; k<=n; k++){
		for(long long i=1; i<=n; i++){
			for(long long j=1; j<=n; j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		long long base=w[x]+w[y],minn=1e18;
		for(long long i=1; i<=n; i++){
			for(long long j=1; j<=n; j++){
				minn=min(minn,t[i][x]+t[j][y]+f[i][j]);
			}
		}
		cout<<base+minn<<endl;
	}
	return 0;
}
