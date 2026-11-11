#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,k,v,u;
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++)cin>>v>>u;
		printf("%d\n",(n-k)/3);
	}
	return 0;
}