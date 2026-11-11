#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int n;
string s;
long long sum=0,cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s=s+' ';
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s=s+c[i];
		}
		sum=sum+a[i];
	}
	for(int i=1;i<=sum/2;i++)
	{
		if(s[i]!=s[sum+1-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
