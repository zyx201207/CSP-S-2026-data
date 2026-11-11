#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+1;
int w[MAXN];
struct node
{
	int k;
	struct student
	{
		int a;
		int t;
	}s1[MAXN];
}s[501];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].k;
		for(int j=1;j<=s[i].k;j++)
		{
			cin>>s[i].s1[j].a>>s[i].s1[j].t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[i]<<endl;
	}
	return 0;
}