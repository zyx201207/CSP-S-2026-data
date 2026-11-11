#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+5]={0};
	char c[n+5];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int i=0;
	int j=n-1;
	int k=0;
	long long cnt=0;
	while(1)
	{
		if(i==j)
		{
			cout<<cnt;
			break;
		}
		k=min(a[i],a[j]);
		if(c[i]!=c[j])
		{
			cnt+=k;
		}
		a[i]-=k;
		a[j]-=k;
		if(a[i]==0)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return 0;
}
