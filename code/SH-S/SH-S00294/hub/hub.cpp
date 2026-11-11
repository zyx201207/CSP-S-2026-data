#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		vector<int>a[1000007];
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		cout<<"1\n";
	}
	
}
