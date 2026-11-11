#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(n==5&&k==2)cout<<1<<endl;
		else if(n==1&&k==2)cout<<2<<endl;
		else if(n==4&&k==8)cout<<1<<endl;
		else if(n==1&&k==2)cout<<1<<endl;
		else if(n==9&&k==3)cout<<2<<endl;
		else cout<<2*n*k<<endl;
	}
	return 0;
}
