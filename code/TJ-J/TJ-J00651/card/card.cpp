#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<int>v;
	long long n,num=0,count=0,m=0;
	char b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num>>b;
		for(long long i=m;i<m+num;i++)
		{
			v.push_back(b);
		}
		m+=num;	
	}
	for(long long i=0;i<m;i++)
	{
		if(v[i]!=v[i+m-i])
		{
			v[i+m-i]=v[i];
			count++;
		}
	}
	cout<<count;
	return 0;
}
