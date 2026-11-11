#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans = 0,pre[500005];

bool cmp(long long a,long long b){
	return a < b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i<=n;i++)pre[i] = pre[i-1]+a[i];
	for(long long i = 1;i<=n;i++){
		long long l = i,r = n,res = 0;
		while(l<=r){
			long long mid = (l+r)/2;
			if(a[mid]*(mid-i+1) - pre[mid]+pre[i-1] <= m){
				res = mid-i+1;
				l = mid+1;
			}
			else r = mid-1;
		}
		ans = max(ans,res);
	}
	cout << ans;
}