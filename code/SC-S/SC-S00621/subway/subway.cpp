#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int a[505][505];
long long n,m,t[505][N],w[N],k[N],c,d,q,cnt[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;i<=k[i];i++){
			long long z;
			cin>>z>>t[i][j];
			cnt[z]++;
			a[z][j]=i;
		}
	}
	long long mi[N][N];
	memset(mi,0x3f3f,sizeof(mi));
	for(int x=1;x<=m;x++){
		if(cnt[x]>1){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(i==j)mi[i][j]=0;
					else mi[i][j]=min(t[i][x]+t[j][x],mi[i][j]);
				}
			}
		}
	} 
	while(q--){
		int x,y;
		long long ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		long long minn=1e9+5;
		for(int i=1,u=a[x][i];a[x][i];i++){
			for(int j=1,v=a[y][j];a[y][j];j++){
				minn=min(mi[u][v]+t[u][x]+t[v][y],minn);
			}
		}
		ans+=minn;
		cout<<ans<<"\n";
	}
	return 0;
}