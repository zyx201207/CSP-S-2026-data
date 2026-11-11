#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		if(n==d){
			cout<<0<<endl;
		}
		else{
				cout<<1;
		}
	}
	return 0;
}