#include<bits/stdc++.h>
using namespace std;
long long int hen,n,m,d,q,k,c,t,i,f,j,u[100005],v[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","r",stdout);
	cin>>c>>t;
	for(j=1;j<=t;j++)
	{
		cin>>n>>k;
		for(i=1;i<=n-1;i++)
		cin>>u[i]>>v[i];
		if(n==2)
		cout<<1;
		else
		cout<<v[i];
	}
	
return 0;
 } 
 // 5 5 1 2 4 8 9
// 5 8 -3 -1 2 2 7
