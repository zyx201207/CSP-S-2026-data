#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long m;
	char k;
	string ans1="";
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		cin>>k;
		for(int i=0;i<m;i++)
		{
			sum+=1;
			ans1+=k;
		}
	}
	sum=sum/2;
	string cut1;
	string cut2;
	for(int i=sum;i<ans1.size();i++)
	{
		cut1+=ans1[i];
	}
	for(int i=sum;i>=0;i--)
	{
		cut2+=ans1[i];
	}
	long long yt=0;
	for(int i=0;i<cut1.size();i++)
	{
		if(cut1[i]!=cut2[i])
		{
			yt+=1;
		}
	}
	cout<<yt;
	return 0;
}
