#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int v[200005];
	vector<int> vv;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	} 
	 sort(v+1,v+n+1,greater<int>());
	 for(int i=1;i<=m;i++)
	 {
	 	vv.push_back(v[i]);
	 }
	 long long sum=vv[0];
	 for(int i=0;i<m;i++)
	 {
	 	sum=(sum&vv[i]);
	 }
	 cout<<sum;
}
