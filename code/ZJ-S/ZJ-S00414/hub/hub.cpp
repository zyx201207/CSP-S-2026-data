#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,T,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		if(n==k) cout<<"0\n";
		if(n/2<=k) cout<<"1\n";
		else{
			int num=(n/2-1)/2+1;
			cout<<(num-k/2-1)/2+1+1<<'\n';
		}
	}
	return 0;
}
