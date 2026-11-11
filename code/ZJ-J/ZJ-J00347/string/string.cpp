#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char ch;
}a[200010];
int n;
long long sum, ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i<=n; ++i){
		scanf("%lld %c", &a[i].num, &a[i].ch);
		sum += a[i].num;
	}
	int l = 1, r = n;
	while (l < r){
		if (a[l].num > a[r].num){
			if (a[l].ch != a[r].ch){
				ans += a[r].num;
			}
			a[l].num -= a[r].num;
			r--;
		}else{
			if (a[l].ch != a[r].ch){
				ans += a[l].num;
			}			
			a[r].num -= a[l].num;
			l++;
		}
	}	
	cout << ans;
	return 0;
}