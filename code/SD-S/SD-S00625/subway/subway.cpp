#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int ids[N];
int f[N][N];
int w[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(f,0x3f3f3f3f,sizeof(f));
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int a1=0,a2=0;
		int t1=0,t2=0;
		if(k==1){
			cin>>a1>>t1;
		}
		else cin>>a1>>t1>>a2>>t2;
		f[a1][a2]=f[a2][a1]=t1+t2;
	}
	for(int i=1;i<=m;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
