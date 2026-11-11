#include<bits/stdc++.h>
using namespace std;
char a[100000];
int t[10000];
char s[100000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		cin>>t[i];
		cin>>a[i];
		for(int j = 1;j <= t[i];j++)
		{
			s[j+ans] = a[i];
		}
		ans += t[i];
	}
	if(n == 1)
	{
		cout<<0;
		return 0;
	}
	bool flag = 0;
	int cnt = 0;
	while(flag == 0)
	{
		for(int i = 1;i <= ans;i++)
		{
			if(s[i] != s[ans + 1 - i])
			{
				cnt++;
				s[ans + 1 - i] = s[i];
			}
		}
		if(cnt == 0)
		{
			cout<<0;
			return 0;
		}
		flag = 1;
	} 
	cout<<cnt;
	return 0;
 } 
