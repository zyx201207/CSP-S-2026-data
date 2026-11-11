#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long  n,m,count=0,num;
	cin>>n>>m;
	vector<long long>v;
	for(long long i=0;i<n;i++)
	{
		cin>>num;
		v.push_back(num);
	}
	sort(v.rbegin(),v.rend());
	count=v[0];
	for(long long i=1;i<m;i++)
	{
		count=count&v[i];
	}
	cout<<count;
	return 0;
}
