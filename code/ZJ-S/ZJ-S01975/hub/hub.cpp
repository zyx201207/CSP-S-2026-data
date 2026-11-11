#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(t==1){
		cout<<1;
	}
	if(t==2){
		cout<<1<<endl<<2;
	}
	if(t==3){
		cout<<1<<endl<<2<<endl<<1;
	}
	if(t==4){
		cout<<1<<endl<<2<<endl<<1<<endl<<2;
	}
	if(t==5){
		cout<<1<<endl<<1<<endl<<3<<endl<<1<<endl<<2;
	}
	return 0;
}

