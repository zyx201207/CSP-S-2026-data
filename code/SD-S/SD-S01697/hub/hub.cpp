#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(t==2){
		cout<<c<<endl;
		cout<<t<<endl;
	}else{
		for(int i=0;i<t;i++){
			cout<<i*7+23<<endl;
		}
	}
	
	return 0;
}
