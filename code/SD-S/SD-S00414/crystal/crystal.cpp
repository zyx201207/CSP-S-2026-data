#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+1+n);
	int l=1,ans=1;
	int sum=a[1];
	for(int i=2;i<=n;i++){
		sum+=a[i];
		int tmp=a[i]*(i-l+1);
		if(tmp-sum>m){
			sum-=a[l];
			tmp-=a[i];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans;
	return 0;
} 
