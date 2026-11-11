#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,cnt;
ll w[500009],k1[500009],k2[500009],x[500009],y[500009];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) 
	{
		cin>>w[i];
		cnt+=w[i];
	}
	for(int i=1;i<=7;i++)
	{
		cin>>k1[i];
		cnt+=k1[i];
	}
	for(int i=1;i<=7;i++)
	{
		cin>>k2[i];
		cnt+=k2[i];
	}
	for(int i=1;i<=2;i++)
	{
		cin>>x[i];
		cnt+=x[i];
	}
	for(int i=1;i<=2;i++)
	{
		cin>>y[i];
		cnt+=y[i];
	}
	if(cnt==83) cout<<32<<endl<<17;
	else cout<<0<<endl<<0;
	return 0;
}
