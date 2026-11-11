#include<bits/stdc++.h>
using namespace std;
long long int a[200005];
long long int l,sum,mid,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n,i,j,k,Min;
	string s[200005];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		l=l+a[i];
	}
		mid=(l+1)/2;
		i=0;
		while(1)
		{
			i++;
			sum=sum+a[i];
			if(sum>=mid) break;
		}
		sum=0;
		k=n;
		for(j=1;j<=i;j++)
		{
			sum=max(a[j],a[k]);
			Min=min(a[j],a[k]);
			if(s[j]!=s[k])
			{
				ans=ans+Min;
				sum=sum-Min;
				if(sum==0)
				{
					k--;
				}
				if(sum!=0)
				{
					while(1)
					{
						if(a[j]<a[k])
						{
							j++;
							if(s[k]!=s[j]) ans=ans+min(a[j],sum);
							sum=sum-min(a[j],sum);
							if(a[j]-min(a[j],sum)<=0) j++;
						}
						else
						{
							k--;
							if(s[k]!=s[j]) ans=ans+min(a[k],sum);
							sum=sum-min(a[k],sum);
							if(a[k]-min(a[k],sum)<=0) k--;
						}
						if(sum==0)
						{
							break;
						}
					}
				}
			}
		}
	cout<<ans;
	return 0;
} 
