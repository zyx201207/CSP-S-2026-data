#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
long long m,n,answ=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int j=n-1;j>=0;j--)
	{
		long long k=1,z=0;
		if(answ>=j)
		{
		    break;
		};
		for(int i=j-1;i>=0;i--)
		{
			z=z+arr[j]-arr[i];
			if(z>m)
			{
				break;
			}
			k+=1;
		};
		if(k>answ)
		{
			answ=k; 
		};
	}
	cout<<answ;
	return 0;
}