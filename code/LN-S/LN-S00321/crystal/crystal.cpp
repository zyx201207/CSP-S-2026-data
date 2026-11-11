#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int d[N];
int preSum[N];
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		preSum[i]=preSum[i-1]+a[i];
	}
	int L=1,R=1;
	while(L<=R&&R<=n){
		int k=(R-L)*a[R]-preSum[R-1]+preSum[L-1];
		if(k<=m){
			ans=max(R-L+1,ans);
			R++;
		}else{
			L++;
		}
	}
	cout << ans;
	return 0;
}
