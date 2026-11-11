#include<bits/stdc++.h>
using namespace std;
int n;
char c[999999999]={};
long long cnt=1;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long num;
		char k;
		cin>>num;
		cin>>k;
		for(long long j=cnt;j<cnt+num;j++)
		{
			c[j]=k;
		}
		cnt=cnt+num;
	}
	for(long long i=1,j=cnt-1;i<=j;i++,j--)
	{
		if(c[i]!=c[j])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}