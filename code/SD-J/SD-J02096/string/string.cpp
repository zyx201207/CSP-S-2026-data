#include<bits/stdc++.h>
using namespace std;
char s[10005];
int a[2005]={0};
char b[2005];
int n;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i] >> b[i];
	int x=1;
	int sum1=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=x; j<=a[i]+x-1; j++)
		{
			s[j] = b[i];
			sum1++;
		}
		x+=a[i];
	}
	bool flag=true;
	for(int i=1; i<=sum1/2; i++)
	{
		if(s[i]!=s[sum1-i+1])
			flag=false;
	}
	if(flag==true)
	{
		cout << "0";
		return 0;
	}
	return 0;
}
