#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2E5 + 10;
int n;
struct node{
	int a;
	char c;
}s[N];
int ans;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i].a >> s[i].c;
	}
	int l = 1, r = n;
	while (l <= r){
		if (s[l].c == s[r].c){
			if (s[l].a < s[r].a){
				s[r].a -= s[l].a;
				s[l].a = 0;
				l++;
			}else if (s[l].a > s[r].a){
				s[l].a -= s[r].a;
				s[r].a = 0;
				r--;
			}
			else{
				s[l].a = 0;
				s[r].a = 0;
				r--;
				l++;
			}
//			cout << "case1 : " << l << " " << r << " " << ans << endl;
//			for(int i = 1; i <= n; i++){
//				cout << s[i].a << " ";
//			}
//			cout << endl;
		}
		else if (s[l].c != s[r].c){
			if (s[l].a < s[r].a){
				ans += s[l].a;
				s[r].a -= s[l].a;
				s[l].a = 0;
				l++;
			}else if (s[l].a > s[r].a){
				ans += s[r].a;
				s[l].a -= s[r].a;
				s[r].a = 0;
				r--;
			}
			else{
				ans += s[l].a;
				s[l].a = 0;
				s[r].a = 0;
				r--;
				l++;
			}
//			cout << "case2 : " << l << " " << r << " " << ans << endl;
//			for(int i = 1; i <= n; i++){
//				cout << s[i].a << " ";
//			}
//			cout << endl;
		}
	}
	cout << ans;
	return 0; 
} 
//双指针贪心， 46和51行卡我40分钟TAT 
