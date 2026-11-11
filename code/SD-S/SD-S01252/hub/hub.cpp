#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T;
int n,k,u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u[i]>>v[i];
		if(k>=n){
			cout<<0<<"\n";
			continue;
		}
		if(k>=n/2){
			cout<<1<<"\n";
		}
		int m=n/2;
		cout<<(m+3-k)/4+1<<"\n";
	}
	
	
	return 0;
}
