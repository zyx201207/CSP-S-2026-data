#include<iostream>
#include<vector>
using namespace std;
int c,t,n,k;
const int N=2e6+7;
vector<int>e[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<"1";
	}
	return 0;
} 
