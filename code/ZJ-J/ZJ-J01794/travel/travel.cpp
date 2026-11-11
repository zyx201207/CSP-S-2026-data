#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
string ca,cb,sa,sb;
void solve(){
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		cout<<1;
	}else{
		cout<<"0000";
		return ;
	}
	bool ok=0;
	if(sa[0]==sb[0]&&sa[1]==sb[1]){
		cout<<1;
		ok=1;
	}else{
		cout<<"000";
		return ;
	}
	if(ok&&((sa[2]<='F'&&sa[2]>='D')&&(sb[2]<='F'&&sb[2]>='D')||(sa[2]<='C'&&sa[2]>='A')&&(sb[2]<='C'&&sb[2]>='A'))){
		cout<<1;
	}else{
		cout<<"00";
		return ;
	}
	int x=sa[2]-'A',y=sb[2]-'A';
	bool no=(x+y==5);
	if(ok&&(abs(x-y)<=1)&&(!no)){
		cout<<1;
	}else{
		cout<<0;
	}
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}

