#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=1e6+5;
int w[N],k[N];
vector<int> a[N];
vector<int> t[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int wasd,wasdt;
			cin>>wasd>>wasdt;
			a[k[i]].push_back(wasd);t[k[i]]
		}
	}
	return 0;
}
