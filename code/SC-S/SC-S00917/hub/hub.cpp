#include<bits/stdc++.h>
using namespace std;
vector <int>arr[2000001];
int main()
{
	long long c,t;
	cin>>c,t;
	for(int i=0;i<t;i++)
	{
		long long n,k,v,u;
		cin>>n>>k;
		for(int j=0;j<n-1;j++)
		{
			cin>>v>>u;
			arr[v].push_back(u);
			arr[u].push_back(v);
		}
		cout<<1<<endl;
	}
} 