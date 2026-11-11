#include <bits/stdc++.h>
using namespace std;
string c,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	double n,i;
	double a = 0,x = 0,z = 0,d = 0,e = 0,j = 0,k;
	cin >> n;
	for(i = 0;i < n;i ++)
	{
		long long a;
	 	cin >> a >> c[i];
	 	if(i == 0)
	 	{
	 		k = a;
		 }
	 	s += a * c[i];
	 	if(a > x && i == 0)
	 	{
	 		x = a;
		 }
		 if(a != k)
		 {
		 	z = 1;
		  } 
	}
	for(i = 0;i <= s.size();i ++)
	{
		if(s[i] != s[i + 1] && i < s.size() )
		{
			d ++;
		}
		if(s[i] == s[i + 1] && i < s.size())
		{
			e += x;
		}
	}
	if(d == 0)
	{
		cout << 0 << "\n";
		return 0;
	}
	else if(z == 0)
	{
		long long l;
		l = (a * x - e) / n;
		cout << x * d << "\n";
		return 0;
	}
	i = 0;
	while(i <  n)
	{
		if(s[i] != s[x])
		{
			
		  s[i] = s[x];
		  a ++;
		}
		i ++;
	}
	cout << a << "\n";
    return 0;
}
