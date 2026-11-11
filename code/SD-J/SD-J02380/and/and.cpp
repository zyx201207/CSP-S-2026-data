#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#define ll long long

using namespace std;

const int N=2e5+5;
ll tp[N];
ll dp[N][20];
ll mn=1e18;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	

memset(dp,127,sizeof(dp));

	ll n,k,mx=-1e18;
	ll flg=1;
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%lld",&tp[i]);
		ll ty=0;
		ll flgg=0;
		while (ty<=30){
			if ((1<<ty)-1==tp[i]){
				flgg=1;
				break;
			}
			ty++;
		}
		if (!flgg) flg=0;
	} 
	if (n-k==1){
		ll ans=1,cnt1=tp[1],cnt2=tp[2];
		for (int i=2;i<=n-1;i++){
			cnt1=(cnt1&tp[i]);
		}
		for (int i=3;i<=n;i++){
			cnt2=(cnt2&tp[i]);
		}
		cout << max(cnt1,cnt2)<<endl;
		return 0;
	}
	
	
	
	for (int i=1;i<=n-k;i++){
		ll t=tp[i];
		for (int j=i+1;j<=i+k;j++){
			t=(t&tp[j]);
		}
		mx=max(mx,t);
	}
	cout << mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
