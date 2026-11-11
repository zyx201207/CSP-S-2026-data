#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans=1e18,a[200005],c,t,x,xx[1000005],yy[1000005],fa[15],dp[15];
vector<int> v[15];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs(int p,int fa){
	dp[p]=min(dp[fa]+1,dp[p]);
	for(int i:v[p])if(i!=fa)dfs(i,p);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>xx[i]>>yy[i];
		}
		if(n>10){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<n;i++){
				v[xx[i]].push_back(yy[i]);
				v[yy[i]].push_back(xx[i]);
			}
		x=1;ans=1e18;
		int y=0,minn=0;
		for(int i=1;i<=n;i++)x*=2,a[i]=0;
		for(int i=1;i<=x;i++){
			a[1]++;
			int p=1;
			while(a[p]>1){
				a[p]-=2;
				a[++p]++;
			}
			minn=0,y=0;
			int xxxx=0;
			for(int i=1;i<=n;i++){
				fa[i]=i;
				xxxx+=a[i];
			}
			if(xxxx!=k)continue;
			for(int i=1;i<n;i++){
				if((a[xx[i]]>0)&&(a[yy[i]]>0)){
					if(find(xx[i])!=find(yy[i])){
						fa[find(xx[i])]=find(yy[i]);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if((a[i]>0)&&(a[j]>0)){
						if(find(i)!=find(j)){
							y++;
							fa[find(i)]=find(j);
						}
					}
				}
			}
			if(y>1)continue;
			dp[0]=-1;
			for(int i=1;i<=n;i++)dp[i]=1e18;
			for(int i=1;i<=n;i++){
				if(a[i])dfs(i,0);
			}
			for(int i=1;i<=n;i++)minn=max(minn,dp[i]);
			ans=min(ans,minn);
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)v[i].clear();
	}
}
