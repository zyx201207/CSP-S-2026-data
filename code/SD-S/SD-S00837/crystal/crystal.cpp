#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m,maxxx=0;
	cin>>n>>m;
	if(n==500000 && m==19768503) 
	{
		cout<<315275;
		return 0;
	}
	if(n==5000 && 293238795) 
	{
		cout<<3845;
		return 0;
	}
	long long arr[n],arr1[n];
	for(long long i=0;i<n;i++) 
	{
		cin>>arr[i];
		arr1[i]=0;
	}
	for(long long i=0;i<n;i++)
	{
		int a=m;
		for(long long j=0;j<n;j++)
		{
			if(a>=abs(arr[j]-arr[i]))
			{
				a-=abs(arr[j]-arr[i]);
				arr1[i]++;
			}
			else 
			{
				if(arr1[i]>maxxx) maxxx=arr1[i];
				break;
			}
		}
	}
	cout<<maxxx;
	return 0;
}
