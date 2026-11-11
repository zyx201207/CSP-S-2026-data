#include<bits/stdc++.h>
using namespace std;
long long int n,i,a[1000000005],j,k,ans,t,flag;
string s,maxn,maxs,v;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>s;
		if(flag==0)
		{
			v=s;
			flag=1;
		}
		if(v==s)
		{
			k++;
		}
		ans+=a[i];
		for(j=1;j<=a[i];j++)
		maxn+=s;
	}
	if(k==n)
	{
		cout<<"0";
		return 0;
	}
	for(j=ans;j>=1;j--)
	{
		maxs[++k]+=maxn[j];
	}
	for(i=1;i<=ans;i++)
	if(maxn[i]!=maxs[i])
	{
		t+=a[i];
	}
	cout<<t/2;
	return 0;
}