#include <bits/stdc++.h>
using namespace std;

long long n,a[200005],ans;
char c[200005];
string s;

int main()
{
	//freopen ("string.in","r",stdin);
	//freopen ("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for (int j=1;j<=a[i];j++)
		{
			s+=c[i];
		} 
	}
	int j=s.size();
	for (int i=0;i<j;i++)
	{
		if (a[i]!=a[j-i-1])
		{
			a[j-i-1]=a[i];
			ans++;
		}
	}
	cout<<ans-1;
	
	return 0;
}
