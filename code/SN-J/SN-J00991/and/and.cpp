#include <bits/stdc++.h>
using namespace std;

long long ans[50] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};

string aaa(long long e)
{
	string s,s1;
	while(1)
	{
		if (e % 2 == 0) s += '0';
		if (e % 2 == 1) s += '1';
		e /= 2;
		if (e == 0) break; 
	}
	for (int i = s.size() - 1;i >= 0; i--) s1 += s[i];
	return s1;
}

string bbb(string a,string b)
{
	string ss;
	if (a.size() != b.size())
	{
		if (a.size() > b.size())
			for (int i = 1;i <= a.size() - b.size(); i++)b += '0';
		else 
			for (int i = 1;i <= b.size() - a.size(); i++)a += '0';
	}
	for (int i = 0;i < a.size(); i++)
	{
		if (a[i] == '1' && b[i] == '1') ss += '1';
		if (a[i] == '1' && b[i] == '0') ss += '0';
		if (a[i] == '0' && b[i] == '1') ss += '0';
		if (a[i] == '0' && b[i] == '0') ss += '0'; 
	}
	return ss;
} 

long long ccc(string s)
{
	long long cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (i == '1') cnt += ans[i]; 
	}
	return cnt;
} 

int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n; i++)
	{
		long long a,b;
		cin >> a >> b;
		cout << ccc(bbb(aaa(a),aaa(b)));
	}
	return 0;
} 
