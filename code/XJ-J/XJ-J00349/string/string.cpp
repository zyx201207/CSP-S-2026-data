#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long a[n];
	string s;
	for(int i = 0;i < n;i ++)
	{
		cin >> a[i];
		cin >> s[i];
	}
	int aa=0;
	for(int i = 0;i < n;i++)
	{
		if(s[i] == s[i + 1])
		{
			aa++;
		}
	}
	if(aa = n-1)
	{
		cout << '0';
	}
	else
	{
		cout << min(a[0],a[n-1]);
	}
}
