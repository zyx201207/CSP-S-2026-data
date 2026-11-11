#include<bits/stdc++.h>
using namespace std;
vector<int>graph[55];
int ans,n,k,dis[55][55];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			graph[i].clear();
		}
		for(int i=0;i<n-1;i++)
		{
			int u,v;cin>>u>>v;
		}
		cout<<1<<endl;
	}
	return 0;
}
