#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, l, r, ans = 0;
struct node{
	int x;//x¸öc
	char c; 
}a[200005];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i].x >> a[i].c;
	l = 1, r = n;
	while(l < r){
		if(a[l].c == a[r].c){
			if(a[l].x > a[r].x){
				a[l].x -= a[r].x;
				a[r].x = 0;
				r--;
			}
			else if(a[l].x == a[r].x){
				a[l].x = 0;
				a[r].x = 0;
				l++, r--; 
			}
			else{
				a[r].x -= a[l].x;
				a[l].x = 0;
				l++;
			}
		}
		else{
			if(a[l].x > a[r].x){
				ans += a[r].x;
				a[l].x -= a[r].x;
				a[r].x = 0;
				r--;
			}
			else if(a[l].x == a[r].x){
				ans += a[l].x;
				a[l].x = 0;
				a[r].x = 0;
				l++, r--; 
			}
			else{
				ans += a[l].x;
				a[r].x -= a[l].x;
				a[l].x = 0;
				l++;
			}
		}
	}
	cout << ans; 
	return 0;
}
