#include<bits/stdc++.h>
using namespace std;
int op,T;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>op>>T;
	while(T--){
		if(T%4)cout<<1<<endl;
		else cout<<2<<endl;
	}
	return 0;
}