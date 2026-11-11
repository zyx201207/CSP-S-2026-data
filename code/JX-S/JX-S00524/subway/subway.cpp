#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
int a[M][25],t[M][25],top[M];
int len[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k;i<=n;i++){
		for(int j=1;j<=n;j++){
			len[i][j]=(long long)1e18;
			if(i==j) len[i][j]=0ll;
		}
		cin>>k;
		for(int j=1,s;j<=k;j++){
			cin>>s;
			a[s][++top[s]]=i;
			cin>>t[s][top[s]];
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<top[k];i++){
			for(int j=i+1;j<=top[k];j++){
				len[a[k][i]][a[k][j]]=min(len[a[k][i]][a[k][j]],t[k][i]+t[k][j]);
				len[a[k][j]][a[k][i]]=min(len[a[k][j]][a[k][i]],t[k][i]+t[k][j]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
		}
	}
	while(q--){
		int x,y,ans=(long long)1e18;
		cin>>x>>y;
		for(int i=1;i<=top[x];i++){
			for(int j=1;j<=top[y];j++)
				ans=min(ans,len[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
 */
