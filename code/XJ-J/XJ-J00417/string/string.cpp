#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char s[N];
char t;
long long int sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	long long int ans=0;
	for(int i=1,j=n;i<j;)
	{
		if(s[i]!=s[j])
		{
			if(a[i]<a[j])
			{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else if(a[i]>=a[j])
			{
				ans+=a[j];
				a[i]-=a[j];
				j--;	
			}
			else
			{
				ans+=a[j];
				i++,j--;
			}
		}
		else
		{
			if(a[i]<a[j]) 
			{
				a[j]-=a[i];
				i++;
			}
			else
			{
				a[i]-=a[j];
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
