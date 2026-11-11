#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l[1000001],sum=0,t=0,s=0;
	char a[1000001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		cin>>a[i];
		sum+=l[i];
	}
	int i=1,j=n;
	while(s<=sum)
	{
		if(l[i]<l[j])
		{
			if(a[i]!=a[j])
			{
				t+=l[i];
			}
			l[j]-=l[i];
			i++;
			s+=l[i];
		}
		else
		{
			if(l[i]>l[j])
			{
				if(a[i]!=a[j])
				{
					t+=l[j];
				}
				l[i]-=l[j];
				j--;
				s+=l[j];
			}
			else
			{
				if(a[i]!=a[j])
				{
					t+=l[j];
				}
				s+=l[i];
				i++;
				j--;
			}
		}
	}
	cout<<t;
	return 0;
}
