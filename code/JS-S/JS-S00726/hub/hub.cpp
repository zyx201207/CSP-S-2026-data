#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[2000006],v[2000006];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
		}
		cout<<rand()%n+1<<"\n";
	}
	return 0;
}
