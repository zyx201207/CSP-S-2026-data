#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<int>v;
	long long n,num=0,count=0,m=0;
	char b;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>num>>b;
		for(long long i=m;i<m+num;i++)
		{
			v.push_back(b);
		}
		m+=num;
		
	}
	for(long long i=1;i<sqrt(m);i++)
	{
		if(v[i]!=v[m+1-i])
		{
			v[m+1-i]=v[i];
			count++;
			cout<<	v[m+1-i]<<' '<<v[i]<<' ';
		}
	}
	cout<<count;
	return 0;
}

