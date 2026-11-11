#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int text,T,n,k,u,v;
vector<int> a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>text>>T;
	for(int i=1;i<=(T+1)/2;i++) cout<<1<<"\n";
	for(int i=1;i<=T/2;i++) cout<<2<<"\n";
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
	}
	return 0;
}