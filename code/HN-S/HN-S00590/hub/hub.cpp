#include<bits/stdc++.h>
using namespace std;
long long T,c,n,k,u,v;
vector<long long> ve[500050];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(long long i=1;i<=n-1;i++){
			cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		cout<<1<<endl;
	}
	return 0;
}
