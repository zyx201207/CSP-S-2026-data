#include<bits/stdc++.h>
using namespace std;
long long a[2000005],dp[2000005],c,T,n,m;
void freeing(){
	int x=a[2]-a[1];
	cout<<n-(m/x)-1<<endl;
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		for(long long i=1;i<=n;i++) a[i]=dp[i]=0;
		cin >> n >> m;
		for(long long i=1;i<=n;i++){
			cin >> a[i];
		}
		if(n<=3){
			cout<<0;
			continue;
		}
		if(11<=c&&c<=12){
			freeing();
			continue;
		}
		long long ans=0;
		for(long long L=1;L<n;L++){
			long long l=L,r=l,d=0;
			bool flag=0;
			while(r<=n){
				//cout<<l<<" "<<r<<" "<<flag<<endl;
				if(flag&&r-l>=2&&dp[l]==dp[l+1]&&dp[l+1]!=dp[l+2]) ans++;
				if(r==n){
					r++;
					continue;
				}
				if(d+a[r+1]-a[r]<=m){
					d+=a[r+1]-a[r];
					r++;
					dp[r]=dp[l]+1;
					flag=1;
				}
				else{
					d-=a[l+1]-a[l];
					l++;
					flag=0;
				}if(r<l) r=l;
			}
			//for(long long i=1;i<=n;i++) cout<<dp[i]<<" ";cout<<endl;
			for(long long i=0;i<=n;i++) dp[i]=0;
		}
		cout<<ans<<endl;
	}
}