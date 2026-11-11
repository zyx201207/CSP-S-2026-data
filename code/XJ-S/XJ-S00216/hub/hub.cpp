#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,u,v,i;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		a.clear();
		a.resize(n+5);
		for(i=1;i<=n;i++)
		{
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
	}
	return 0;
}
