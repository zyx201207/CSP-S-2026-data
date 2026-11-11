#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char k[200005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>k[i];
	}
	int i=1,j=n;
	while(i<j)
	{
		if(k[i]==k[j])
		{
			if(a[i]<a[j])
			{
				a[j]-=a[i];
				i--;
			}
			else if(a[j]<a[i])
			{
				a[i]-=a[j];
				j--;
			}
			else
			{
				i++;
				j--;
			}
		}
		if(k[i]!=k[j])
		{
			if(a[i]<a[j])
			{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else if(a[j]<a[i])
			{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else
			{
				ans+=a[i];
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
