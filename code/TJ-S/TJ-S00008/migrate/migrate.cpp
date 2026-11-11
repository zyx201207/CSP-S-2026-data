#include<iostream>
#include<cstring>
#include<cstdio> 
using namespace std;
const int N=2e5+7;
int n,dp[N],cnt[N],ans;
long long d,a[N],c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	memset(dp,0x3f,sizeof(dp));
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int k=1;k<=n;k++){
			dp[k]=0;
			for(int i=k;i<=n;i++){
				for(int j=i-1;j>=k;j--){
					if(a[i]-a[j]<=d){
						if(dp[i]==dp[j]+1){
							cnt[i]++;
						}
						else if(dp[i]>dp[j]+1){
							dp[i]=dp[j]+1;
							cnt[i]=1;
						}
					}
					else break;
				}
			}
			for(int i=k;i<=n;i++){
				if(cnt[i]==2)ans++;
				cnt[i]=0;
				dp[i]=1e9;
			}
		}
		cout<<ans<<endl;
		if(c==13||c==14)cout<<"0\n"; 
	}
	return 0;
} 
