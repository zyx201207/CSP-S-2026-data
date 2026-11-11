#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll i,c,t,n,k,u[N],v[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=1;i<=n;i++)cin>>u[i]>>v[i];
		if(n%2==0)cout<<2;
		else cout<<1;
		cout<<"\n";
	}
	return 0;
}
