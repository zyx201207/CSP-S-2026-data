#include <bits/stdc++.h>
using namespace std;

long long c[200010];
long long ci[200010];
string s[200010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long mx = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>c[i]>>s[i];
		mx = max(mx,c[i]);
	}
	if(n <= 2000 && mx <= 2e3)
	{
		string t = ""; 
		for(int i = 0; i < n; i++)
		{
			cin>>c[i]>>s[i];
			for(int j = 1; j <= c[i]; j++)
			{
				t += s[i];
			}
		}
		int l = 0,r = t.size() - 1;
		long long sum = 0;
		while(l <= r)
		{
			if(t[l] != t[r])
			{
				sum++;
			}
			l++;
			r--;
		}
		cout<<sum<<endl;
	}
	else
	{
		long long sum = 0;
		int l = 0,r = n - 1;
		while(l < r)
		{
			if(c[l] == c[r])
			{
				if(s[l] != s[r])
				{
					sum += c[l];
				}
				l++;
				r--;
			}
			else//ccbcc 
			{
				if(c[l] < c[r])
				{
					sum += c[r];
					c[r] -= c[l];
					l++;
					if(s[l] == s[r])
					{
						sum -= (r - c[l - 1]);
					}
					r--;
				}
				else
				{
					sum += c[l];
					c[l] -= c[r];
					r--;
					if(s[r] == s[l])
					{
						sum -= (l - c[r - 1]);
					}
					l++;
				}
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;	
}
