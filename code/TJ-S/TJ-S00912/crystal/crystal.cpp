#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long n,m;
long long a[500005];
long long pre[500005];
long long maxn = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		pre[i] = pre[i-1]+a[i];
	}
	for(long long i = 1;i<=n;i++){
		int l = 1,r = i;
		int cnt;
		while(l<=r){
			int mid = (l+r)/2;
			int x = a[i]*(i-mid+1)-(pre[i]-pre[mid-1]);
			if(x<=m){
				cnt = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		maxn = max(maxn,1LL*(i-cnt+1));
//		cout << ans << endl; 
		
	}
	cout << maxn;
	return 0;
} 
