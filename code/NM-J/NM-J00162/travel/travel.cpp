#include<bits/stdc++.h>
using namespace std;
string rc,xc;
string rs,xs;
int ans[5];
bool ri(char x){
	if(x=='F'||x=='D'){
		return 1;
	}else {
		return 0;
	}
}
bool le(char x){
	if(x=='A'||x=='B'||x=='C'){
		return 1;
	}else {
		return 0;
	}
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> rc >> rs >> xc >> xs;
    //num
    if(rc==xc) {
    	cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int x=rs[2];
	int y=xs[2];
	//row
	if(rs[0]==xs[0]&&rs[1]==xs[1]){
		cout<<1;
	}else {
		cout<<0<<0<<0;
		return 0;
	}
	//side
	if( ( ri(x)&&ri(y) )||( le(x)&&le(y) ) ){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	//near
	if(ri(x)&&ri(y)) {
		if(x+1==y||y+1==x){
			cout<<1;
			return 0;
		}else {
			cout<<0;
			return 0;
		}
	}else if(le(x)&&le(y)){
		if(x+1==y||y+1==x){
			cout<<1;
		}else {
			cout<<0;
		}
	}else{
		cout<<0;
		return 0;
	}
    return 0;
}
