#include <bits/stdc++.h>
using namespace std;
long long n,ans,num;
string x,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while (n--) {
		cin >> num >> x;
		for (int i = 1;i <= num;i++) {
			s1 += x;
		}
	}
	s2 += s1;
	reverse(s2.begin(),s2.end());
	for (int i = 0;i < s1.size();i++) {
		if (s1[i] == s2[i]) continue;
		ans++;
	}
	cout << ans / 2;
	return 0;
}
