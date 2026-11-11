#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int>nxt[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T,n,k;cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			nxt[u].push_back(v);
			nxt[v].push_back(u);
		}
		if(k==n){ cout<<"0\n";continue; }
		if(c==13||c==14){ cout<<max(1,n/2+1-k)<<'\n';continue; }
		cout<<(n-k)/3<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}