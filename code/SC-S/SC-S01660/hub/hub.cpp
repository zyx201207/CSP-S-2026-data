#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int uuu=1;uuu<=t;uuu++)
	{
		int n,k,a,b;
		m=n/2;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++) 
		{
			cin>>a>>b;
		}
		if(m==k) cout<<0<<endl;
		else if(m-k+1>1) cout<<m-k+1<<endl;
		else cout<<1<<endl;
	}
	return 0;
 } 