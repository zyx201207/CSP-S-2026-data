#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 200001;
int n, ans, sum;
struct Node{
	int num;
	char c;
}a[MAXN];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++){
		cin >> a[i].num;
		cin >> a[i].c;
	}
	int l = 1, r = n;
	while (l < r){
		if (a[l].c != a[r].c){
			if (a[l].num > a[r].num){
				sum += a[r].num;
				a[l].num -= a[r].num;
				a[r].c = a[l].c;
				r--;
			}
			else if (a[l].num < a[r].num){
				sum += a[l].num;
				a[r].num -= a[l].num;
				a[l].c = a[r].c;
				l++;
			}
			else if (a[l].num == a[r].num){
				sum += a[l].num;
				l++, r--;
			}
		}
		else if (a[l].c == a[r].c){
			if (a[l].num < a[r].num)
				a[r].num -= a[l].num, l++;
			else if (a[r].num < a[l].num)
				a[l].num -= a[r].num, r--;
			else if (a[l].num == a[r].num)
				l++, r--;
		}
	}
	printf ("%lld\n", sum);
	return 0;
}
