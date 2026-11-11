#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll sum[N],a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	ll m; cin >> n >> m;
	bool ok=1;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int d = a[2]-a[1];
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1] != d){
			ok=0;
			break;
		}
		
	if(ok==1){
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(a[n]-a[i]);
		for(int i=1;i<=n;i++)
			if(sum[n]-sum[i-1] <= m){
				ans = n-i+1;
				break;
			}
		cout << ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		int s=0;
		memset(sum,0,sizeof(sum));
		for(int j=1;j<=i;j++) sum[j]=sum[j-1]+(a[i]-a[j]);		
		for(int j=1;j<=i;j++)
			if(sum[i]-sum[j-1] <= m){
				s=i-j+1;
				break;
			}
		ans = max(ans,s);
	}
	cout << ans;
	return 0;
} 
