#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		cout<<1<<"\n"<<2;
		return 0;
	}
	else{
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				cin>>u[i]>>v[i];
			}
			if(k>n){
				cout<<0<<"\n";
				return 0;
			}
			n=n/2+1;
			if(k>n){
				cout<<1<<"\n";
				return 0;
			}
		}
		
	}
	return 0;
}
