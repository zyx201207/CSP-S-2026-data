#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1,a2,b2;
	char b10,b20;
	cin>>a1>>b1>>b10>>a2>>b2>>b20;
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}
	if(b1!=b2){
		cout<<1000;
		return 0;
	}
	if(!((b10<='C'&&b20<='C')||(b10>='D'&&b20>='D'))){
		cout<<1100;
		return 0;
	}
	if(!((b10-b20==1)||(b20-b10==1))){
		cout<<1110;
		return 0;
	}
	cout<<1111;
	return 0;
}

