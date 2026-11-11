#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[200010];
string c[200010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <=n ;i++)
	{
		cin >> a[i] >> c[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= a[i];j++)
		{
			s+=c[i];
		}
	}
	int ans = 0;
	string k = s;
	reverse(s.begin(),s.end());
	if(k == s)
	{
		cout << 0;
		return 0;
	}
	else
	{
		//int l = 0,r = n-1;
		for(int i = 0;i < s.size()/2;i++)
		{
			//if(l != r)
			//{
				if(s[i] != k[1])
				{
					ans++;
				}
				//l++;
				//r--;
			//}
			//else
			//{
				//break;
			//}
		}
	}
	cout << ans;
	return 0;
 } 
