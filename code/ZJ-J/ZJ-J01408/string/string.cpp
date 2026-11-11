#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200010],s[200010];
char c[200010];

int sl(int x,int y){
	return s[y] - s[x - 1];
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l = 0;
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		s[i] = s[i - 1] + a[i];
		l += a[i];
	}
	int mid = l / 2;
	int ans = 0;
	int cur = 0,i = 1,j = n;
	while(i != j && cur < mid){
		int d = min(sl(1,i),sl(j,n));
		//cout << cur << " " << i << " " << j << endl;
		if (c[i] != c[j]){
			ans += d - cur;
		}
		cur = d;
		if (cur >= sl(1,i)){
			i++;
		}
		if (cur >= sl(j,n)){
			j--;
		}
	}
	cout << ans << endl;
	return 0;
} 
