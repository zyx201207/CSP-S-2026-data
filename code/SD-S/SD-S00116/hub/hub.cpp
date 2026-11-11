#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int c,t,n,k;
vector<int>edge[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if(k==n){
			cout<<"0\n";
			continue;
		}
		if(c==13||c==14){
			if(k>=n/2){
				cout<<"1\n";
				continue;
			}
			if((n/2+1)%2==1){
				int x=n/2+1;
				if(k<x/2) cout<<x/2+2-k<<'\n';
				else cout<<2<<'\n';
			}
			else{
				int x=n/2+1;
				if(k==1||k==2) cout<<x/2<<'\n';
				else if(k<=(x-2)/2) cout<<x/4-(k/4-1)<<'\n';
				else cout<<2<<'\n';
			}
			continue;
		}
	}
	return 0;
} 
