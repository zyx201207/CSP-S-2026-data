#include <bits/stdc++.h>
using namespace std;
int n, a[200003];
char c[200003];
long long b; 
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		b+=a[i];
	}
	long long l=1, r=n, cnt = 0;
	long long ans = 0;
	long long mid=b/2;
	while(cnt<=mid&&l<r) {
		int minn = min(a[l],a[r]);
		cnt+=minn;
		if(c[l]!=c[r]) {
			ans+=minn;
		}
//		printf("%d %d %d %d\n",l, r, c[l], c[r]);
//		cout << mid << endl;
		a[l]-=minn;
		a[r]-=minn;
		if(a[l]==0) l++;
		if(a[r]==0) r--; 
	}
	cout << ans;
	return 0;
} 
