#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int c,T,a[N],f[N],dp[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c<=10){
		while(T--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)f[j]=dp[j]=0;
				int l=i;
				while(l<n){
					int x=l;
					for(int r=l+1;r<=n;r++)
						if(a[r]-a[l]<=d){f[r]=f[l]+1;x=r;}					
						else break;
					if(x==l)break;
					l=x;
				}
				dp[i]=1;
				l=i;int r=i;
				for(int j=i+1;j<=n;j++){
					if(f[j]==0)break;
					while(f[r]<=f[j]-1)r++;r--;
					while(f[l]<f[j]-1||a[j]-a[l]>d&&l<=r)l++;
					dp[j]=dp[j-1]+dp[r]-dp[l-1];
					if(dp[j]-dp[j-1]==2)ans++;
				}
			}			

			cout<<ans<<"\n";
		}	
		return 0;	
	}
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int m=1,l=1,r=1,ans=0; 
		for(int i=1;i<=n;i++){
			while(m<=n&&a[m]-a[i]<=d)m++;
			m--;
			if(m==n)break;
			while(r<=n&&a[r]-a[m-1]<=d)r++;
			r--;
			while(l<=n&&a[l]-a[max(m-2,0ll)]<=d)l++;
			l--;
			ans+=r-l;
		}
		cout<<ans<<"\n";
	}
}
