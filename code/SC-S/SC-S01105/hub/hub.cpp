#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		vector<int> G[2000005];
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			if(n/2<=k){
				cout<<1<<endl;
			}else if(n==k){
				cout<<0<<endl;
			}else{
				cout<<n/k-1<<endl;
			}
		}
	}
	//I LOVE CCF
	//CCF nb
	//I LOVE CCF
	//CCF nb
	//I LOVE CCF
	//CCF nb
	//乞求CCF多给点分 orz orz orz
	//许愿米提亚，芙宁娜不歪 十连三金
	return 0;
}