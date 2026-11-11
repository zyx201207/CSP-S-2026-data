#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,c,sum=0;
	string str;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >>a;
		for (int j=1;j<=a;j++)
		{
			cin >> c;
			str+=c;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(str[i]!=str[n-i])
		{
			str[i]=str[n-i];
			sum++;
		}
	} 
	cout << str;
	return 0;
}
