#include <iostream>
using namespace std;
string s = "";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,ct = 0;
	char c;
	cin >> n;
	for (long long i = 1; i <= n; ++i) {
	    scanf("%lld %c",&a,&c);
	    while (a--) s += c;
	}
//	cout << s << endl;
	for (long long i = 0; i < s.size() / 2; ++i) {
	    if (s[i] != s[s.size() - 1 - i]) ct++;
	}
	cout << ct;
	return 0;
}
