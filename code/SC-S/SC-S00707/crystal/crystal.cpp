#include<bits/stdc++.h>
using namespace std;
long long a[500005], b[500005], ans, m, n;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int p = 2; p <= n; p++) {
		long long num=m,cnt=0;
		for(int i=p;i>0;i--){
			if(num-a[p]+a[i]<0){
				break;
			}
			else{
				num=num-a[p]+a[i];
				cnt++;
			}
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
}