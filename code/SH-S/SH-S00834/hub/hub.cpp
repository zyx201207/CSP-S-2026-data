#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k,u,v;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		if(k==1){
			cout<<n-(n+1)/2<<endl;
		}else{
			cout<<(((n+1)/2)-(k-k/2)+1)/2<<endl;
		}
	}
	return 0;
}
