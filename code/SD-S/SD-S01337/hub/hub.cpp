#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		if(n==k){
			cout<<0<<"\n";
		}else if(n==k+1){
			cout<<1<<"\n";
		}else if(n==k+2){
			cout<<2<<"\n";
		}else{
			cout<<n*(n-1)/k<<"\n";
		}
	}
	return 0;
}
