#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int c,t,n,k,u,v;
vector<int> ve[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			if(u<v) swap(u,v);
			ve[u].push_back(v);
		}
		cout<<k-1<<endl;
	}
	return 0;
}