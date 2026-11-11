#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000005];
char l;
string s;
long long num;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (long long i=1;i<=n;i++){
		cin>>a[i]>>l;
		for (long long j=1;j<=a[i];j++) s+=l;
	}
	/*for (int i=1;i<=s.length()/2;i++)
	{
		for (int j=s.length()/2+2;j<s.length();j++)
		{
			if (s[i]!=s[j]) 
			{
				s[j]=s[i];
				num++;
			}
		}
	}*/
	long long l=s.length()/2,r=s.length()/2+2;
	while (l>0)
	{
		if (s[l]!=s[r])
		{
			s[r]=s[l];
			num++;	 
		}
		l--;
		r++;
	}
	cout<<num;
	return 0;
}
