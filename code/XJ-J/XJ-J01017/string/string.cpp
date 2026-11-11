#include <iostream>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,f=1;
	long long minn=1000000005;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		minn=min(minn,a[i]);
	}
	for(int i=2;i<=n;i++)
	{
		if(c[i]!=c[i-1])
		{
			f=0;
		}
	}
	if(f==1)
	{
		cout<<0;
		return 0;
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cout<<minn;
		return 0;
	}
	return 0;
}