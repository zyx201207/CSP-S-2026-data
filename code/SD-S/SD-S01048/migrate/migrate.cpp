#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000010],dp[2000010],dp2[2000010],lst[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int l=1,r=2;
		while(r<=n){
			while(a[r]-a[l]>d)l++;
			lst[r]=l;
			r++;
		}
		if(c<=6){
			int ans=0;
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					dp[i]=4e18;
					dp2[i]=0;
				}
				dp[k]=0;
				dp2[k]=1;
				for(int i=k+1;i<=n;i++){
					for(int j=max(k,lst[i]);j<i;j++){
						if(dp[j]+1<dp[i]){
							dp[i]=dp[j]+1;
							dp2[i]=dp2[j];
						}else if(dp[j]+1==dp[i]){
							dp2[i]+=dp2[j];
						}
					}
				}
				for(int i=1;i<=n;i++){
					ans+=bool(dp2[i]==2);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
//-static-libgcc
