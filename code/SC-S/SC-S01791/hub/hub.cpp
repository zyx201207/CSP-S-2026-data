#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		cout<<((n+1)/2-k+3)/4+1;
	}
	return 0;
}