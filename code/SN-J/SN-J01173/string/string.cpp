//王昭云  西安市曲江第一学校  SN-J01173
#include <iostream>

using namespace std;

long long n,a,ans; 
char c;
string s; 

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a;
		cin >> c;
		for(int j = 1;j <= a;j++)
			s += c;
	}
	//两个指针，遍历
	int l = 0,r = s.size() - 1;
	while(l <= r)
	{
		if(s[l] != s[r])
			ans++;
		l++;
		r--;
	}
	cout << ans;
	return 0;
}

