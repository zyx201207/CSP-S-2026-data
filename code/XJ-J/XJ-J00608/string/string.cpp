#include<bits/stdc++.h>
using namespace std;
string c[1000005];
long long int a[1000005],n,k,s,i,t=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(i=0;i<n-1;i++)
	{
		if(c[i]!=c[i+1])
		{
			t=0;
		}
	}
	if(t==1)
	{
		cout<<'0';
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(c[i]==c[0])
		s+=a[i];
		else
		{
			break;
		}
	}
	cout<<s;
	return 0;
}