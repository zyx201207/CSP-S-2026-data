#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u>>v;
		int m=(n>>1)+2;
		int f=ceil((m-k)*1.0/3);
		cout<<max(f+1,1)<<'\n';
	}
	return 0;
}
