#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[10005];
	long long sum=0;
	string m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>m[i-1];
		sum+=a[i];
	}
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		if(m[i-1]!=m[i]&&i<n)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<0;
		return 0;
	}
	cout<<sum/2;
	return 0;
}
