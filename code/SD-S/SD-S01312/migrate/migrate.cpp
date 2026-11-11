#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,M=2e6+10;
int t,n,a[M],nxt[M],lst[M],d,ans,dis[N][N],vis[N][N],c;
void di(int x){
	for(int i=x,p=1;i<=n;i=nxt[i],p++){
		vis[x][i]=1;
		for(int j=i+1;j<=nxt[i];j++)dis[x][j]=p;
		if(nxt[i]==i)break;
	}
}
void solve(int x){
	for(int i=x;i<=n;i++){
		int cnt=0;
		for(int j=x+1;j<i;j++){
			cnt+=(vis[x][j]==0&&dis[x][j]+dis[j][i]==dis[x][i]);
			if(cnt>=2)break;
		}
		if(cnt==1)ans++;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			int len=d/(a[2]-a[1]);
			for(int i=1;i<=n;i++)ans+=max(0LL,(n-i)/len-1);
			if(len==1)ans=0;
			cout<<ans;
			continue;
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=vis[i][j]=0;
		for(int l=1,r=1;l<=n;l++){
			while(r<=n&&a[r]-a[l]<=d)lst[r]=l,r++;
			nxt[l]=r-1;
		}
		for(int i=1;i<=n;i++)di(i);
		for(int i=1;i<=n;i++)solve(i); 
		cout<<ans<<"\n";
	}
	return 0;
}
