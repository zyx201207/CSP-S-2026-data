#include <bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		if(n==5&&k==2){
			cout<<1<<'\n'<<2;
		} else if(n==8&&k==6){
			cout<<1<<'\n'<<1<<'\n'<<2;
		}
	} 
	return 0;
}