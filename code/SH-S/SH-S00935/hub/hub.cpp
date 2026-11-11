#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k,u,v;
vector<int>e[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1;i<n;i++)
        {
        	cin>>u>>v;
        	e[u].push_back(v);
        	e[v].push_back(u);
		}
		cout<<(n-k)/3<<endl;
	}
	return 0;
}
