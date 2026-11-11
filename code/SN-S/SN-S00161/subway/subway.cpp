#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,d,q,len[500010],k[500010],a[500010][21],b[500010][21],mp[510][510];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>t>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>len[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x][0]++;
			a[x][a[x][0]]=i;
			b[x][a[x][0]]=y;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=a[k][0];i++){
			for(int j=1;j<=a[k][0];j++){
				if(i!=j){
					mp[a[k][i]][a[k][j]]=min(mp[a[k][i]][a[k][j]],b[k][i]+b[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		mp[i][i]=0;
	}
	for(int k=1;k<=n;k++){	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=1;i<=a[x][0];i++){
			for(int j=1;j<=a[y][0];j++){
				ans=min(ans,mp[a[x][i]][a[y][j]]+b[x][i]+b[y][j]+len[x]+len[y]);
			}
		}
		cout<<ans<<"\n";
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

*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
