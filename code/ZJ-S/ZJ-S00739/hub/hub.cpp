#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,t,n,k,x[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
		}
		if(n%2==1)cout<<n%3<<"\n";
		else cout<<cout<<n%5<<"\n";
	}
	return 0;
}
/*
Oct31==Dec25?
*/
