#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int a[N];
char s[N];
int main()
{
	freopen("string.in" , "r" ,stdin);
	freopen("string.out","w",stdout);
	
	
	//×¢ÊÍ£¡£¡£¡£¡£¡ 
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	if(n == 2)
	{
		int a , b;
		char c , d;
		cin >> a >> c >> b >> d;
		if(c == d)
		{
			cout << 0;
			return 0;
		}
		cout << min(a,b); 
		return 0;
	}
	long long ans=0;
	bool flag = true;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> s[i];
		//cout << a[i] << ' ';
		ans+=a[i];
	}
	for(int i = 2; i<=n; i++)
	{
		if(s[i] != s[i-1])
		{
			flag = false;
		}
	}
	if(flag == true)
	{
		cout << 0; 
	}
	else
	{
		cout <<ans/2;
	}
	return 0;
}
