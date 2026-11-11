#include <bits/stdc++.h>
using namespace std;
bool is_huiwen(string a,int sum)
{
	for (int i = 0;i < a.size()/2;i++)
	{
		for (int j = a.size()-1;j >= a.size()/2+1;j--)
		{
			if (a[i]!=a[j])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n,num=0;
	int a[200006];
	string s,m;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> m;
		for (int j = 1;j <= a[i];j++)
		{
			s+=m;
			num++;
		}
	}
	int num1=0;
	if (is_huiwen(s,num))
	{
		cout << 0;
	}
	else
	{
		string z=s;
		for (int i = s.size();i > s.size()/2;i--)
		{
			for(int j = 0;j < z.size();j++)
			{
				if (z[j]!=s[i])
				{
					num1++;
				}
			}
		}
		cout << num1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}