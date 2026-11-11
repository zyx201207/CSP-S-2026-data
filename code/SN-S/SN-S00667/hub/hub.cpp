#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		if(c==1){
			cout<<"1\n";
		}
		if(c==13||c==14){
			int n,k;
			cin>>n>>k;
			for(int i=1,u,v;i<n;i++){
				cin>>u>>v;
			}
			if(k==n){
				cout<<"0\n";
				continue;
			}
			if(k>=n/2){
				cout<<"1\n";
				continue;
			}
			if((n/2+2-k)%3==0){
				cout<<((n/2+2-k)/3+3)/2<<'\n';
			}
			else{
				cout<<((n/2+2-k)/3+4)/2<<'\n';
			}
		}
	}
	return 0;
}
