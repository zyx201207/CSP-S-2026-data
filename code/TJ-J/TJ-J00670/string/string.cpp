#include<bits/stdc++.h>
using namespace std;
long long n;
struct Data
{
	long long a;
	char c;
}a[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin >> n;
	long long l = 0;
	for(long long i = 0;i<n;i++)
	{
		cin >> a[i].a >> a[i].c;
		l+=a[i].a;
	}
	long long k = 0;
	for(long long i = 0;i<n;i++)
	{
		long long ci = a[i].a;
		for(long long j = 0;j<ci;j++)
		{
			k++;
			s[k] = a[i].c;
		}
	}
	long long cnt = 0;
	if(l%2==0) 
	{
		for(long long i = 1;i<=k/2;i++)
		{
			if(s[i]!=s[l+1-i])
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	else
	{
		for(long long i = 1;i<=k/2+1;i++)
		{
			if(s[i]!=s[l+1-i])
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

