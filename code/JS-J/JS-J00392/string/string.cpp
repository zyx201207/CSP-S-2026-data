#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	char c[n];
	vector <char> arr;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(long long i=0;i<n;i++)
	{
		long long z=0;
		for(long long j=0;j<a[i];j++)
		{
			arr[z]=c[i];
			z++;
		}
	}
	long long m=(arr.size()-1)/2;
	char brr[m];
	for(long long i=0;i<=m;i++)
	{
		brr[i]=arr[i];
	}
	long long sum=0;
	if(m%2==0)
	{
		for(long long i=(arr.size()-1)/2+1;i<arr.size();i++)
		{
			if(arr[i]!=brr[2*((arr.size()-1)/2)-i+1])
			{
				sum++;
			}
		}
	}
	else
	{
		for(long long i=(arr.size()-1)/2;i<arr.size();i++)
		{
			if(arr[i]!=brr[2*((arr.size()-1)/2)-i])
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
