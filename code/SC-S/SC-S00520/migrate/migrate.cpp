#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,a[2000005],b[2000005],dp[2000005],j=1,dis[2000005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1)dp[i]=a[i]-a[i-1];
			if(a[i]-a[i-1]>d){
				b[j]=i-1;
				j++;
			}
		}
		if(b[1]==2){
			cout<<0<<endl;
			break;
		}
		int cnt=0;
		for(int i=2;i<=n;i++){
			if(dp[i+1]=dp[i]&&i!=n)cnt++;
			break;
		}
		if(cnt==n-2){
			cout<<0<<endl;
            break;
		}
		cout<<b[1]%d+1;
	}
	return 0;
}
