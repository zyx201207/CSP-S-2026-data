#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node{
	long long a;
	char c;
}s[N], l[N], r[N];
long long cnt1, cnt2, ans, n;
unsigned long long len1, len2, len;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> s[i].a >> s[i].c;
		len1 += s[i].a;
	}
	len1 /= 2;
	len2 = len1;
	for (int i = 1; i <= n; i++){
		if (s[i].a <= len1){
			l[++cnt1].a = s[i].a;
			l[cnt1].c = s[i].c;
			len1 -= s[i].a;
		}
		else {
			if (len1 == 0) break;
			else{
				l[++cnt1].a = len1;
				l[cnt1].c = s[i].c;
				s[i].a -= len1;
				break;
			}
		}
	}
	for (int i = n; i >= 1; i--){
		if (s[i].a <= len2){
			r[++cnt2].a = s[i].a;
			r[cnt2].c = s[i].c;
			len2 -= s[i].a;
		}
		else {
			if (len2 == 0) break;
			else{
				r[++cnt2].a = len2;
				r[cnt2].c = s[i].c;
				break;				
			}
		}
	}
	for (int i = 1, j = 1; i <= cnt1;){
		if (l[i].a > r[j].a){
			len = l[i].a - r[j].a;
			l[i].a = len;
			if (l[i].c != r[j].c) ans += r[j].a;
			j++;
		}
		else {
			if (l[i].a < r[j].a){
				len = r[j].a - l[i].a;
				r[j].a = len;
				if (l[i].c != r[j].c) ans += l[i].a;
				i++;
			}
			else{
				if (l[i].c != r[j].c) ans += l[i].a;
				i++;
				j++;
			}
		}
	}
	cout << ans;
	return 0;
} 
