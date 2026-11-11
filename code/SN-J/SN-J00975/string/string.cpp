#include <bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,sum=0,d1=0,d2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		cin>>s[i];
	}
	int i=1;
	while(i<(n+1)/2)
	{
		for(int j=n;j>=(n+1)/2;j--)
		{
			if(d1!=0)
			{
				if(s[i]==s[i-1])
				{
					a[i]+=d1;
					d1=0;
				}
				else if(s[i-1]==s[j])
				{
					a[j]-=d1;
					d1=0;
				}
				else
				{
					cnt+=d1;
					a[j]-=d1;
					d1=0;
				}
			}
			if(d2!=0)
			{
				if(s[j]==s[j+1])
				{
					a[j]+=d2;
					d2=0;
				}
				else if(s[j+1]==s[i])
				{
					a[i]-=d2;
					d2=0;
				}
				else
				{
					cnt+=d2;
					a[i]-=d2;
					d2=0;
				}
			}
			if(s[i]!=s[j])
			{
				if(a[i]>a[j])
				{
					cnt+=a[j];
					d1=a[i]-a[j];
				}
				else{
					cnt+=a[i];
					d2=a[j]-a[i];
				}
			}
			else{
				if(a[i]>a[j])
				{
					d1=a[i]-a[j];
				}
				else{
					d2=a[j]-a[i];
				}
			}
		}
		i++;
	}
	if(n%2==1)
	{
		cnt--;
	}
	cout<<cnt<<"\n";
}
