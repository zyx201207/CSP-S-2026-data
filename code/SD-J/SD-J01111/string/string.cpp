#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200005];
	long long sum=0;
	char b[200005];
	if(n==1)
	{
		cout<<0; 
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		cin>>b[i];
	}
	sum=(sum-1)/2;
	if(n==2)
	{
		cout<<min(a[1],a[2]);
	}
	return 0; 
} 

