#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,d,c,v;
	cin>>s>>d>>c>>v;
	if(d==v){
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s==c){
		cout<<1;
	}
	else cout<<0;
	if(d[1]==v[1]){
		cout<<1;
	}
	else cout<<0;
	if(d[1]==v[1]&&d[2]<='C'&&v[2]<='C'){
		cout<<1;
	}
	else if(d[1]==v[1]&&d[2]>='D'&&v[2]>='D'){
		cout<<1;
	}
	else cout<<0;
	if(d[1]==v[1]&&d[2]<='C'&&v[2]<='C'&&(d[2]-v[2]==1||v[2]-d[2]==1)){
		cout<<1;
	}
	else if(d[1]==v[1]&&d[2]>='D'&&v[2]>='D'&&(d[2]-v[2]==1||v[2]-d[2]==1)){
		cout<<1;
	}
	else cout<<0;
	
	return 0;
}
