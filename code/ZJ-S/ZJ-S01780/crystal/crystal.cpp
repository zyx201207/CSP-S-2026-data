#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, pos, ans;
long long m, a[N], s[N];
bool check(int mid, int x){
	long long cha = s[mid] - s[x - 1];
	if(cha + m >= a[mid] * (mid - x + 1))return true;
	else return false;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++){
		int l = i, r = n;
		while(l <= r){
			int mid = (l + r) / 2;
			if(check(mid, i)){
				l = mid + 1;
				pos = mid;
			}
			else {
				r = mid - 1;
			}
		}
		//cout << pos - i + 1 << endl;
		ans = max(ans, pos - i + 1);
	}
		

	printf("%d", ans);
	return 0;
}
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/

