#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+100; 
const int MX = 1e12;

int n,m,ans;
int a[N],sum[N];

int find(int x){
	int l = 1ll,r = x,mid,aaa=1ll;
	while(l<=r){
		mid = (l+r)/2;
		if(a[x]*(x-mid+1ll)-sum[x]+sum[mid-1ll]<=m){
			r = mid-1ll;
			aaa = mid;
		}else{
			l = mid+1ll;
		}
	} 
	return aaa;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
//		a[i]+=MX;
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i] += sum[i-1] + a[i];
		
		if(a[i]==a[i+1]&&i!=n){
			continue;
		}
		ans = max(ans,i-find(i)+1);
	}
	cout << ans;
	return 0;
}
