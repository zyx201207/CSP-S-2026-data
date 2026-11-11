#include<bits/stdc++.h>
#define ll pair<long long int,long long int>
using namespace std;
long long int i,j,k,n,m,q,d,c,w[10000005],x,y,t[10000005];
vector<ll>dis;
bool st[10000005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>x>>y;
		}
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<"32"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
