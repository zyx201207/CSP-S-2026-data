#include<bits/stdc++.h>
using namespace std;
string s, s1;
long long n, x, tt = 1;
long long ans = 0;
char c, bc;
bool b = 1;
pair<long long, char> a[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		cin >> x >> c;
		a[i].first = x;
		a[i].second = c;
		if(bc != c && i != 1) b = 0;
		bc = c;
	}
	if(b)
	{
		cout << 0;
		return 0;
	}
	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 1; j <= a[i].first; j++)
		{
			s[tt] = a[i].second;
			tt++;
		}
	}
	for(long long i = 1; i <= tt / 2; i++) 
	{
		s1[i] = s[i]; 
		s1[tt - i] = s[i];
	}
	for(long long i = 1; i <= tt; i++)
		if(s1[i] != s[i]) ans++;
	cout << ans << endl;
	return 0;
} 
