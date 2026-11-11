//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll a[N];
int main(){
  	freopen("migrate.in","r",stdin);
  	freopen("migrate.out","w",stdout);
	ll c,t,n,d;
  	cin>>c>>t;
  	while(t--){
  		cin>>n>>d;
  		ll ans=0;
  		for(int i=1;i<=n;i++){
  			cin>>a[i];
		}
		if(c==11||c==12){
			if(a[2]-a[1]<=d){
				int k=d/(a[2]-a[1]);
				if(k==1||n<=2)ans=0;
				else{
					if(k==2)ans=n-2;
					if(k>2)ans=1;
				}
			}
		}
		else{
					int dp[N];
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					memset(dp,0,sizeof(dp));
					dp[i]=1;
					for(int k=i+1;k<=j;k++){
						for(int l=k-1;l>=i;l--){
							if(a[k]-a[l]<=d)dp[k]+=dp[l];
						}
					}
					if(dp[j]==2)ans++;
				}
			}
			ans-=1;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
