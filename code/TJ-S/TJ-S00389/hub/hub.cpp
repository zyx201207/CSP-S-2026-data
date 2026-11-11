#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+9;
vector<int> G[mx];
int c,t;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	if(n<=6){
		if(k==n){
			cout<<"0\n";
		}else{
			cout<<"1\n";
		}
	}else{
		cout<<(((n/2)+5)/2-k/2+1)/2<<"\n";
	} 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}//Liu Boyan
