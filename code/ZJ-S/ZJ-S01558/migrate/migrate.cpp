#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,D,a[2000010],dp[5010][5010],f[5010][5010],flag[5010][5010],e[2000010];
void dij(int x){
	dp[x][x]=0;
	for(int i=x+1;i<=n;i++){
		int l=x,r=i-1,ans=-1;
		while(l<=r){
			int mid=(r-l)/2+l;
			if(a[i]-a[mid]<=D)ans=mid,r=mid-1;
			else l=mid+1;
		}
		if(ans==-1)dp[x][i]=2e18,f[x][i]=0;
		else f[x][i]=(ans==x),dp[x][i]=dp[x][ans]+1;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>c>>T;
	while(T--){
		cin>>n>>D;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			int d=a[2]-a[1];
			if(d>=D)cout<<"0\n";
			else cout<<max(0ll,n-(D/d)*2+1)<<'\n';
			continue;
		}
		if(c==13||c==14){
			int ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]-a[1]<=D&&a[n]-a[i]<=D)ans++;
			if(ans>=3)cout<<"0\n";
			else cout<<"1\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=2e18,f[i][j]=0,flag[i][j]=0;
		for(int i=1;i<=n;i++)
			dij(i);	
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<n;k++)
				if(flag[i][k]==0)
					for(int j=k+1;j<=n;j++){
						if(dp[i][k]+dp[k][j]==dp[i][j]){
							f[i][j]+=f[i][k]*f[k][j];
							if(f[i][j]>=3)flag[i][j]=1;
						}
				}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(f[i][j]==2)ans++;
		cout<<ans<<'\n';
	}	
	return 0;
}