#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
LL a[N];
char ch[N];
LL ans;
string str;
int n;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i] >> ch[i];
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= a[i]; j ++) str += ch[i];
	int l = 0, r = str.length() - 1;
	//cout << str << endl;
	while(r - l > 0)
	{
		if(str[l] != str[r]) ans ++;
		//cout << str[l] << " " << str[r] << endl;
		l ++;
		r --;
	}
	cout << ans << endl;
	return 0;
} 
