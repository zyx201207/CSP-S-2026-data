#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+10,Nmin=1e3;
ll n,m,a[N],ans,dp[Nmin][Nmin],qian[N],hou[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,(ll)a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}else if(m==n-1){
		qian[1]=a[1],hou[n]=a[n];
		for(int i=2;i<=n;i++){
			qian[i]=(qian[i-1]&a[i]);
		}
		for(int i=n-1;i>=1;i--){
			hou[i]=(hou[i+1]&a[i]);
		}
		ans=hou[2];
		for(int i=2;i<=n;i++){
			ans=max(ans,(ll)qian[i-1]&hou[i+1]);
		}
		cout<<ans;
		return 0;
	}else{
		dp[1][1]=a[1];
		for(int i=2;i<=n;i++){
			dp[i][1]=a[i];
			for(int k=2;k<=min((ll)i,m);k++){
				for(int j=1;j<i;j++){
					dp[i][k]=max(dp[i][k],(ll)dp[j][k-1]&a[i]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[i][m]);
		}
		cout<<ans;
	}
	return 0;
}
