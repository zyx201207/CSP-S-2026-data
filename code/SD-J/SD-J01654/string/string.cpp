#include<iostream>
using namespace std;
char c[10000010];
char a[10000010];
long long ans,p=1;
bool check()
{
	for(int i=p-1;i>=1;i--)
	{
		a[i]=c[p-i];
	}
	for(int i=1;i<=p-1;i++)
	{
		if(a[i]!=c[i]) return 0;
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char s;
		cin>>x>>s;
		for(int j=p;j<=p+x-1;j++)
		{
			c[j]=s;
		}
		p+=x;
	}
	for(int i=1;i<=p-1;i++)
	{
		if(c[i]!=c[p-i])
		{
			c[p-i]=c[i];
			ans++;
			if(check()==1)
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
