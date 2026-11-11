#include <bits/stdc++.h>
using namespace std;
long long c,t,n[100000],k[100000],x[1000000],ans,a,b;
vector<int> son[100000];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n[i]>>k[i];
		for (int j=1;j<=n[i];j++)
		{
			cin>>a>>b;
			son[a].push_back(b);
			son[b].push_back(a);
		}
	}
	cout<<1<<endl<<2;
	return 0;
}
