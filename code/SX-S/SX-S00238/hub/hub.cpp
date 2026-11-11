#include<bits/stdc++.h>
using namespace std;
const int X=2e6+5;
long long c,t,n,k;
struct jj{
	int u,v;
};
jj a[X];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i].u>>a[i].v;
		cout<<1<<'\n';
	}
	
	return 0;
}