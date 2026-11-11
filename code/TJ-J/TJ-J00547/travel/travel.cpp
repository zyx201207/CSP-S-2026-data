//20261031-cspj-00547-t1
#include<bits/stdc++.h>
using namespace std;
int main(){
	//redirect
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//EEEEEEEEEZZZZZZZZZZZZZZZZZZZ
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	//debug
	//cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
	//1
	if(a==c){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	//2
	if(b.substr(0,2)==d.substr(0,2)){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	//3
	if((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	//4
	if(b[2]+1==d[2]||d[2]+1==b[2]){
		cout<<"1";
	}else{
		cout<<0;
		return 0;
	}

	return 0;
}
