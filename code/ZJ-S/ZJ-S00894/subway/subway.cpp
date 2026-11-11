#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e2+10,M=5e5+10;
int c,n,m,d,q;
int ans=LLONG_MAX;
int w[M];
int a[N][2005],t[N][2005];
int cnt[M],b[M][25],ak[2005],vis[M];
void dfs(int x,int y,int sum){
	if(x==y){
		ans=min(ans,sum);
		return ;
	}
	for(int k=1;k<=cnt[x];k++){
		int i=b[x][k];
		for(int j=1;j<=ak[i];j++){
			if(vis[a[i][j]]) continue;
			vis[a[i][j]]=1;
			dfs(a[i][j],y,sum+t[i][j]+t[a[x][x]][x]);
			vis[a[i][j]]=0;
		}
		
	}
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;ak[i]=k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			int forwards=a[i][j];
			cnt[forwards]++;
			b[forwards][cnt[forwards]]=i;
		}
	}
	while(q--){
		ans=LLONG_MAX;
		int x,y;cin>>x>>y;
		dfs(x,y,0);
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}