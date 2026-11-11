#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int dp[2*N];
int ans;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n==m){
		cout<<sum;
		return 0;
	}
	if(n-1==m){
		ans=-1;
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				cnt=(ans&a[j]);
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	
	
	
	return 0;
}
