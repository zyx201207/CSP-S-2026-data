#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,q,a[N],s[N][50],t[N];
int k,x,y,w[N][50],f[605][605];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){ 
		cin>>a[i];
	}
	for(int i=1;i<=600;i++){
		for(int j=1;j<=600;j++){
			f[i][j]=0x3f;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			t[x]++;
			s[x][t[x]]=i;
			w[x][t[x]]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=t[i];j++){
			f[s[i][j]][s[i][j]]=0;
			for(int k=1;k<=t[i];k++){
				f[s[i][j]][s[i][k]]=min(f[s[i][j]][s[i][k]],1ll*w[i][j]+w[i][k]);
				f[s[i][k]][s[i][j]]=min(f[s[i][k]][s[i][j]],1ll*w[i][j]+w[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		int ans=1e18;
		for(int j=1;j<=t[x];j++){
			for(int k=1;k<=t[y];k++){
				ans=min(ans,w[x][j]+w[y][k]+f[s[x][j]][s[y][k]]);
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
// 
