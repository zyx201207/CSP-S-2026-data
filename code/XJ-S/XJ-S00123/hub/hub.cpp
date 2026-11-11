#include <bits/stdc++.h> 
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k;
		cin>>n>>k;
		int v[n],u[n];
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
		}
		if(n>k)
		{
			cout<<(n-k+1)/2<<endl;
		}
		else
		{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
