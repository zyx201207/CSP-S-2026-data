#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010],s[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	int sum=0,t=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
		while(a[i]--)
		{
			s[t]=c[i];
			t++;
		}
		sum+=a[i];	
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	else if(n==2)
	{
		if(c[1]==c[0])
			cout<<0;
		else
		{
			if(a[1]==a[0])
				cout<<a[0];
			else
				cout<<max(a[0]-a[1],a[1]-a[0]);	
		}	
		return 0;
	}
	else
	{
		int ans=0;
		for(int i=0;i<=t%2;i++)
		{
			if(s[i]!=s[t-i-1])
				ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
