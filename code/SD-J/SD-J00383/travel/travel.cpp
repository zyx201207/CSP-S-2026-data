#include <bits/stdc++.h>

using namespace std;
struct czx{
	string x,w;
}a,b;
bool px(string x,string y){
	if(x[0]==y[0]&&x[1]==y[1]){
		return true;
	}
	return false;
}
bool pp(string x,string y){
	if(x[0]==y[0]&&x[1]==y[1]){
		return true;
	}
	return false;
}
bool pc(char x,char y){
	if(x<='C'&&y<='C'){
		return true;
	}
	if(x>='D'&&y>='D'){
		return true;;
	}
	return false;
}
bool pl(char x,char y){
	if(abs(int(x-y))==1){
		return true;
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.x>>a.w>>b.x>>b.w;
	if(px(a.x,b.x)){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(pp(a.w,b.w)){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(pc(a.w[2],b.w[2])){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0; 
	}
	if(pl(a.w[2],b.w[2])){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
