#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200067;
ll ans=0;
ll a[N];ll n,l;
ll dp[N];
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	int T_T;cin>>T_T>>T_T;
	while(T_T--){
		ans=0; 
		cin>>n>>l;for(int i=1;i<=n;i++)cin>>a[i];
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++)dp[i]=0;
			dp[k]++;
			
			for(int i=1;i<=n;i++){
				for(int m=i;m<=n;m++){
					if(a[i]-l<a[m]&&a[i]>=a[m]){
						dp[m]+=dp[i];
					}
				}
			}
			
			for(int i=1;i<=n;i++){
				if(dp[i]==2)ans++;
			}
		}
		cout<<ans/2;
	}
}


