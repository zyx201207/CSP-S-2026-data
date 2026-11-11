#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int x,y;
			cin>>x>>y;
		}
		if(k==2) cout<<1<<"\n";
		else cout<<int((k*1.0)/2+0.5)<<"\n";
	}
	return 0; 
}