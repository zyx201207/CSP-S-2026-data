#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[200005],cnt=0,cnt1=0,sum[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
		for(long long j=sum[i-1];j<sum[i];j++)
		{
			s[j]=c[i];
			cnt1++;
		}
	}
	for(long long i=0;i<=cnt1/2;i++)
	{
		if(s[i]!=s[cnt1-1-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
