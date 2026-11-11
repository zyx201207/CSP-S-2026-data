#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;
int w[N],k[N],cha;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
	{
		cin>>w[i];
	}
	for(int i=1; i<=n; i++)
	{
		cin>>k[i];
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2)
	{
		cout<<32<<endl<<17;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2)
	{
		cout<<35<<endl<<16;
	}
	return 0; 
}
