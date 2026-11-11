#include<iostream>
using namespace std;
int c,t;
int k=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cout<<k<<'\n';
		k+=4;
	}
	return 0;
}
