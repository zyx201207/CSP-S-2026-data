#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=305;
int n,m,a[maxn],dis[maxn][maxn];
bool vis[maxn];
int calc(int l,int r){
	int ans=0;
	for(int i=l;i<r;i++)
	for(int j=i+1;j<=r;j++){
		int lst=i,cnt=0;
		for(int k=i;k<=j;k++)
		if(a[k]-a[lst]>m) cnt++,lst=k;
		dis[i][j]=cnt+1;
		//cout<<i<<' '<<j<<' '<<dis[i][j]<<"\n";
	}
	for(int i=l;i<r;i++)
	for(int j=i+1;j<=r;j++){
		memset(vis,0,sizeof vis);
		int lst=i,cnt=0;
		for(int k=i;k<=j;k++)
		if(a[k]-a[lst]>m) lst=k,vis[k-1]=true;
		for(int k=i+1;k<j;k++)
		if(!vis[k]&&dis[i][k]+dis[k][j]==dis[i][j]) cnt++;
		if(cnt>=1) ans++;
	}
	return ans;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int lst=1,ans=0;
	for(int i=1;i<=n;i++){
		if(i==n||a[i+1]-a[i]>m){
			ans+=calc(lst,i);
			lst=i+1;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;cin>>t>>t;
	while(t--) solve();
	return 0;
}