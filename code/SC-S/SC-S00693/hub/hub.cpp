#include<bits/stdc++.h> 
using namespace std;
int c,t,n,k,a,b;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a>>b;
		}cout<<n/k-1<<"\n";
	}
	return 0;
}