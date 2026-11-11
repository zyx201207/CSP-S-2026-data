#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int cnt;
	char c;	
}a[200005];
long long n, ans, check;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].cnt >> a[i].c;
	}
	check = n;
	for(int i = 1;a[i].cnt != 0;i++){
		if(a[i].cnt > a[check].cnt){
			if(a[i].c != a[check].c){
				ans += a[i].cnt - a[check].cnt;
			}
			a[i].cnt -= a[check].cnt;
			a[check].cnt = 0;
			check--;
			i--;
		}
		else{
			if(a[i].cnt == a[check].cnt){
				if(a[i].c != a[check].c){
					ans += a[check].cnt;
				}
				a[i].cnt = a[check].cnt = 0;
				check--;
			}
			else{
				if(a[i].c != a[check].c){
					ans += a[check].cnt - a[i].cnt;
				}
				a[check].cnt -= a[i].cnt;
				a[i].cnt = 0;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}