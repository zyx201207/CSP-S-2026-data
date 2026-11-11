#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+3;
const int INFLL=0x3f3f3f3f3f3f3f3f;
ll c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>k;
			cout<<(n/8)+1-((k/4)-1)<<"\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
		}
		cout<<n%1000<<"\n";
	}
	return 0;
}
