#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int MAXN=500010;

int n,m,k,mi,ma;
int a[MAXN],sum[MAXN];
bool oka=1,okb=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) oka=0;
	}
	sort(a+1,a+1+n);
	k = a[n]-a[n-1];
	for (int i=1;i<n;i++){
		if (a[i+1]-a[i]!=k){
			okb = 0;
			break;
		}
	}
	if(oka){
		for (int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
		for (int i=1;i<=n;i++){
			if (sum[i]>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(okb){
		for (int i=1;i<=n;i++) sum[i] = sum[i-1]+i*abs(k);
		for (int i=1;i<=n;i++){
			if (sum[i]>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	int ans=1;
	for (int i=1;i<=n;i++){
		int sum=0,cnt=1;
		for (int j=i-1;j>0;j--){
			sum += a[i]-a[j];
			if (sum>m){
				ans = max(ans,cnt);
				break;
			}
			cnt++;
		}
		ans = max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
