#include<bits/stdc++.h>
using namespace std;
char s[100001];
int n,sum,c,ans;
int a[10001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		char z;
		cin>>a[i]>>z;
		sum+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s[cnt]=z;
			cnt++;
		}	
	}
	if(sum%2==0)
	{
		int j=0;
		for(int i=sum/2+1;i<=sum;i++)
		{
			if(s[i]!=s[i-(2*j+1)])ans++;
		}	
	}
	else
	{
		int j=1;
		for(int i=(sum+1)/2+1;i<=sum;i++)
		{
			if(s[i]!=s[i-2*j])ans++;
		}
	}
	cout<<ans;
	return 0;
} 
