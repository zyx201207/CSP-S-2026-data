#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 5;
int n;
long long ans;
struct Node {
	char ch;
	long long num;
}a[Maxn];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].num >> a[i].ch;
	}
	int lt = 1, rt = n;
	while(lt <= rt){
		if(a[lt].ch == a[rt].ch){
			if(a[lt].num < a[rt].num){
				a[rt].num -= a[lt].num;
				a[lt].num = 0;
				lt++;
			}
			else if(a[lt].num == a[rt].num){
				a[rt].num = 0;
				a[lt].num = 0;
				lt++;
				rt--;
			}
			else if(a[lt].num > a[rt].num){
				a[lt].num -= a[rt].num;
				a[rt].num = 0;
				rt--;
			}
		}
		else{
			if(a[lt].num < a[rt].num){
				a[rt].num -= a[lt].num;
				ans += a[lt].num;
				a[lt].num = 0;
				lt++;
			}
			else if(a[lt].num == a[rt].num){
				ans += a[lt].num;
				a[rt].num = 0;
				a[lt].num = 0;
				lt++;
				rt--;
			}
			else if(a[lt].num > a[rt].num){
				a[lt].num -= a[rt].num;
				ans += a[rt].num;
				a[rt].num = 0;
				rt--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

