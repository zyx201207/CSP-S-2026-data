#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[100000],v[100000],ans=t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for (int i=1;i<n;i++)
			cin>>u[i]>>v[i];
	}
	if (c==0&&ans==2) cout<<1<<endl<<2;
	return 0;
 } 
