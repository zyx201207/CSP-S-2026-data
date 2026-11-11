#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int l = 0;
	for (int i = 1;i <= n;i++){
		int x;
		char c;
		cin >> x >> c;
		l += x;
		for (int j = 1;j <= x;j++) s = s + c;
	}
	string s2;
	s2 = s;
	reverse(s2.begin(),s2.end());
	int sum = 0;
	for (int i = 0;i < l / 2;i++){
		if (s[i] != s2[i]) sum++;
	}
	cout << sum;
	return 0;
}//wo yao shang mi huo xing wei da shang. 100 + 56 + ? + ? = 156 + ?
