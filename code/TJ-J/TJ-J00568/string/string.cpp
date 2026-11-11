#include<bits/stdc++.h>
#include<cstring>
#include<cmath>
#include<iostream> 
using namespace std;
string s1,s2;
int main()
{
	long long int n,sum=0,mid,ans=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		string s;
		cin>>k>>s;
		sum+=k; 
		for(int j=1;j<=k;j++)
		{
			s1+=s;
		}
	}
	mid=sum/2;
	for(int i=0;i<mid;i++)
	{
		if(s1[i]!=s1[sum-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
