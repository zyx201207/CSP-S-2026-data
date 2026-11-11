#include<bits/stdc++.h>
using namespace std;
int a[800000],log1[10000],fan[10000];
int jilu[1000];
bool flag;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	log1[0]=1;
	for(int i=1;i<=30;i++)
	{
		log1[i]=2*log1[i-1];
	}
	jilu[31]=n+1;
	for(int i=n;i>=1;i--)
	{
		for(int j=30;j>=1;j--)
		{
			if((a[i]<log1[j])&&(a[i]>=log1[j-1]))
			{
				fan[i]++;
				jilu[j]=i;
			}
		}
	}
	int ans=0;
	for(int i=30;i>=1;i--)
	{
		if(fan[i]>=m)
		{
			ans=a[jilu[i+1]-1];
			flag=true;
			for(int j=jilu[i+1]-1;j>=jilu[i+1]-m;j--)
			{
				ans=ans&a[j];
			}
			break;
		}
	}
	if(flag==false)
	{
		ans=a[n];
		for(int i=n;i>=n-m+1;i--)
		{
			ans=ans&a[i];
		}
	}
	cout<<ans;
    return 0;
}
