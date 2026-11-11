#include<bits/stdc++.h>
using namespace std;
const int N=510,M=1100;
long long int w[M],a[N],f[M][M],dis[M];
vector<int> v[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,m,n,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			int k98,k71;
			cin>>k98>>k71;
		}
		long long int x,y,t1,t2;
		cin>>x>>t1>>y>>t2;
		f[x][y]=f[y][x]=t1+t2;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(f[i][k]+f[k][j]>f[i][j])f[i][j]=f[i][k]+f[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int st,en;
		cin>>st>>en;
		cout<<w[st]+w[en]+f[st][en]<<"\n";
	}
	return 0;//let me ac!!
}
