#include<iostream>
#include<cstdio>
using namespace std;
int a[1000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<'1';
		return 0;
	}
	int cha=a[2]-a[1];
	while(m>0&&ans<n)
	{
		if(m>=cha)
		{
			ans++;
			m=m-cha;
			cha=cha*2;
		}
		else
			break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
