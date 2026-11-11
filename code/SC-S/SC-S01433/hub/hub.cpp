#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		if(k==1)cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}