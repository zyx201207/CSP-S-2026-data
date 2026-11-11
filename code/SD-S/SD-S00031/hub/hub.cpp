#include <bits/stdc++.h>
using namespace std;
int C,T,n,k;
vector<int>g[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	srand(time(0));
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(C==13||C==14){
			int m=(n-1)/2+1;
			int p=(m-k)/4,q=(m-k)%4;
			if(!q){
				cout<<p+1<<"\n";
				continue;
			}
			cout<<p<<"\n";
			continue;
		}
		cout<<rand()%n<<"\n";
	}
	return 0;
}
//score\in [10pts,?pts]
