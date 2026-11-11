#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int c,t;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		vector<int>to[2000005];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		cout<<(n-k)/2<<endl;
	}
	return 0;
}
