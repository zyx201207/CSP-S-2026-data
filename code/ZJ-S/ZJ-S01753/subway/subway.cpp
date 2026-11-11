#include<bits/stdc++.h> // 15:19
#define ll long long
using namespace std;
const int N=5e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[N],id[N][22],cnt[N],t[N][22];
ll dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
//	cerr<<q<<'\n';
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,a;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			cnt[a]++;
			id[a][cnt[a]]=i;
			cin>>t[a][cnt[a]];
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=1;k<=cnt[i];k++){
				if(j==k) continue;
				dis[id[i][j]][id[i][k]]=min(dis[id[i][j]][id[i][k]],(ll)t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(j==k||j==i) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int x,y;
	ll ans;
	while(q--){
		cin>>x>>y;
		ans=inf;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,t[x][i]+t[y][j]+dis[id[x][i]][id[y][j]]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
} // 15:33 15:48

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
