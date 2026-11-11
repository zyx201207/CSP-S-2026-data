#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
string c1,c2,c3,c4;
string k1,k2;
void solve(){
	if(c1==c3){
		cout<<1;
	}else{
		cout<<"0000";
		return ;
	}
	if(c2[0]==c4[0] && c2[1]==c4[1] && ((c2[2]<='C' && c4[2]<='C') || (c2[2]>='D' && c4[2]>='D'))){
		cout<<1;
	}else{
		cout<<"000";
		return ;
	}
	if((c2[2]<='C' && c4[2]<='C') || (c2[2]>='D' && c4[2]>='D')){
		cout<<1;
	}else{
		cout<<"00";
		return ;
	}
	if(abs(c2[2]-c4[2])==1){
		cout<<1;
	}else{
		cout<<0;
		return ;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
//	cout<<c1<<c2<<c3<<c4;
	solve();
	return 0;
}
//02 01C 02 01A

