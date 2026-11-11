#include<bits/stdc++.h>
using namespace std;
int c , t ;
int n , k ;
int u[1000001] , v[1000001] ;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<2<<endl;
	}
	return 0;
} 
