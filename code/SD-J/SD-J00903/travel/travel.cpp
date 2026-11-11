#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rk,rs,xk,xs;
	cin>>rk>>rs>>xk>>xs;
	if(rk==xk){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(rs[0]==xs[0]&&rs[1]==xs[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((rs[2]>='A'&&rs[2]<='C'&&xs[2]>='A'&&xs[2]<='C')||(rs[2]>='D'&&rs[2]<='E'&&xs[2]>='D'&&xs[2]<='E')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(rs[2]+1==xs[2]||rs[2]-1==xs[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
