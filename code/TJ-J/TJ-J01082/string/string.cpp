#include <iostream>
using namespace std;
long long n,ans=0;
long long a[1000000000+5];
char c[1000000000+5];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin >>n;
	string str;
	for (long long i = 1;i <= n;i++)
	{
		cin >>a[i]>>c[i];
		while (a[i]--)
		{
			str+=c[i];
		}
	}
	if(str.size()%2==1)
	{
		long long i=0,j=str.size()-1;
		while (i+2!=j)
		{
			if (str[i]!=str[j]) ans++;
			i++,j--;
		}
		if (str[i]!=str[j]) ans++;
	}
	else if (str.size()%2==0)
	{
		long long i=0,j=str.size()-1;
		while (i+1!=j)
		{
			if (str[i]!=str[j]) ans++;
			i++,j--;
		}
	}
	cout <<ans;
	return 0;
}
