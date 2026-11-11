#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
	}
	cout<<(n-k+1)/2<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	while(T--) solve();
	return 0;
}
