#include<bits/stdc++.h>
using namespace std;
int n,l=0,ans=0;
string a[10005];
int sum[1000005];
string word[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>sum[i];
		cin>>word[i];
	}
	for(int i=0;i<n;i++)
	{
		l+=sum[i];
	}
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<sum[i];j++)
		{
			a[k]=word[i];
			k++;
		}
	}
	for(int i=0;i<l/2;i++)
	{
		if(a[i]!=a[l-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
}
