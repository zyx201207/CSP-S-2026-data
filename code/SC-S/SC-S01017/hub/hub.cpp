#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0)cout<<1<<endl<<2;
	else{
		while(t--){
			cout<<t%2+1;
		}
	}
	return 0;
}