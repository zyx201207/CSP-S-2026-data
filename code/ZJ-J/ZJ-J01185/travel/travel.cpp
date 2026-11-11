#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,c,d,e,f;
void cmp(char x,char y){
	if((x<='C'&&y>='D')||(x>='D'&&y<='C')){
		cout<<"00";
		return ;
	}
	cout<<"1";
	if((x=='D'&&y=='F')||(x=='F'&&y=='D')){
		cout<<"1";
		return ;
	}
	if(abs(y-x)==1){
		cout<<"1";
		return ;
	}
	cout<<"0";
	return ;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		e+=b[0];
		e+=b[1];
		f+=d[0];
		f+=d[1];
		if(e==f){
			cout<<"1";
			cmp(b[2],d[2]);
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
