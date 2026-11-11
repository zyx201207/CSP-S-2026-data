#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10,INF=1e18;
int c,n,m,d,q,w[M];
int f[N][N];
int s[M],t[M][21][2];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)f[i][j]=INF;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,x,y;
		cin>>k;
		while(k--){
			cin>>x>>y;
			s[x]++;
			t[x][s[x]][0]=i;
			t[x][s[x]][1]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=s[i];j++){
			for(int k=1;k<=s[i];k++){
				int x=t[i][j][0],y=t[i][k][0];
				int w1=t[i][j][1],w2=t[i][k][1];
//				cout<<x<<" "<<y<<" "<<w1<<" "<<w2<<endl;
				f[x][y]=min(f[x][y],w1+w2);
				f[y][x]=min(f[y][x],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(int i=1;i<=s[x];i++)
			for(int j=1;j<=s[y];j++){
				int t1=t[x][i][0],t2=t[y][j][0];
				ans=min(ans,f[t1][t2]+t[x][i][1]+t[y][j][1]);
			}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}/*
5 5
1 2 4 8 9
*/
