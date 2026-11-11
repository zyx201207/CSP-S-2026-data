#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],d;
long long ans;
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1]>>b[1];
	char k=b[1];
	int flag=0;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(b[i]!=k)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<0;
		return 0;
	}
	else
	{
		for(int i=1,j=n;i<=j;)
		{
			if(b[i]!=b[j])
			{
				if(a[i]>a[j])
				{
					ans+=a[j];
					a[i]-=a[j];
					j--;
				}
				else if(a[i]<a[j])
				{
					ans+=a[i];
					a[j]-=a[i];
					i++;
				}
				else
				{
					ans+=a[j];
					i++;
					j--;
				}
			}
			else
			{
				if(a[i]>a[j])
				{
					a[i]-=a[j];
					j--;
				}
				else if(a[i]<a[j])
				{
					a[j]-=a[i];
					i++;
				}
				else
				{
					i++;
					j--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
