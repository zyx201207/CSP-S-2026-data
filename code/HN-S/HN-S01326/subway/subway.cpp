#include<bits/stdc++.h>
using namespace std;
struct T
{
	int id,t;
};
int c,n,m,d,q,w[500005];
vector<int> v[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,s;i<=n;i++)
	{
		cin>>s;
		for(int j=1,a,t;j<=s;j++)
			cin>>a>>t;
	}
	int s,e;
	while(q--)
	{
		cin>>s>>e;
		cout<<w[s]+w[e];
	}
	return 0;
}

