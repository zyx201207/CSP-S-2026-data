#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
char s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0,sum=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		ans+=a[i];
	}
	bool p=1;
	for(int i=1;i<=n-1;i++)
	{
		if(s[i]!=s[i+1]) p=0;
	}
	if(p==1)
	{
		cout<<0;
		return 0;
	}
	if(ans%2==0)
	{
		int h=n,g=n;
		for(int i=1;i<=n/2;i++)
		{
			if(s[i]!=s[h])
			{
				if(a[i]==a[g]) sum+=a[i];
				sum+=max(a[i],a[g])-min(a[i],a[g]);
			}
			g--;
		}
	}
	else
	{
		int r=n,t=n;
		for(int i=1;i<=n/2+1;i++)
		{
			if(s[i]!=s[r])
			{
				if(a[i]==a[t]) sum+=a[i];
				else sum+=(max(a[i],a[t])-min(a[i],a[t]))/2;
			}
			t--;
		}
	}
	cout<<sum;
	return 0;
}
