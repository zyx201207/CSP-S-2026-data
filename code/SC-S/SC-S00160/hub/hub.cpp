#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> a[1000010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
	}//虽然只写了输入，但我要上洛谷
	
	return 0;
}
