#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
char c[N];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	int n;
	cin >> n;
	string s;
	int sum=0;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];
		sum+=a[i];
		for (int j = 1; j <= a[i]; j++) {

			s.push_back(c[i]);
		}


	}
	
	int cnt = 0;
	if (sum%2==0){
		for (int i = 0; i < s.size()/2; i++) {
			
			if (s[i-1] == s[s.size()-i]) {     
				cnt += 0;
			} else {
				cnt++;
			}
			
			
		}
	}else{
		for (int i = 0; i <= s.size()/2; i++) {
			
			if (s[i-1] == s[s.size()-i]) {     
				cnt += 0;
			} else {
				cnt++;
			}
			
			
		}
	}
	
	
	
	cout << cnt;
	return 0;
}
