#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","l",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	char s[200005];
	long long a[200005],Unsum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	for(int i=n/2;i>=1;i--)
	{
	for(int j=1;j<=a[i];i++){
		if(s[i]!=s[n-i+1])
		{
			Unsum+=a[i]-j+1;
			break;
		}
		else
		{
			Unsum+=a[i]-j+1;
			break;
		}
		a[i]--;
		a[n-i+1]--;
	}
}
cout<<Unsum;
	return 0;
}