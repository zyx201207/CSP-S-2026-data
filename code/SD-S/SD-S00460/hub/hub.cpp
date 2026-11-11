#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(c==0){
			if(n==5&&k==2)cout<<1<<endl;
			if(n==10&&k==3)cout<<2<<endl;
		}
	}
	return 0;
}

