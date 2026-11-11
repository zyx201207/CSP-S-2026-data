#include <bits/stdc++.h>
using namespace std;
long long a[100001];
char c[100001];
string s,l;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
			l+=c[i];
		}
		k+=a[i];
	}
	int sum=0;
	sort(l.begin(),l.end());
	if(s==l)
	{
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=k/2;i++)
	{
		if(s[i]==s[k-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}