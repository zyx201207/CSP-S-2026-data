#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)
	{
		int n,m;cin>>n>>m;
		for(int i=1;i<=2*n-2;i++)
		{
			int x;cin>>x;
		}
		int k=n/2;
		if(m==n)cout<<0<<"\n";
		else if(m>=k)cout<<1<<"\n";
		else cout<<ceil((k-m)/4.0)+1<<"\n";
	}
}
