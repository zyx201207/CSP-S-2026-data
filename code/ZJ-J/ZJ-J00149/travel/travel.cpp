#include<bits/stdc++.h>
using namespace std;
string x1="",x2="",y1="",y2="";
char x3,y3;
bool check_side(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='D'||b=='F')return false;
		else return true;
	}
	if(b=='D'||b=='F'){
		if(a=='A'||a=='B'||a=='C')return false;
		else return true;
	}
}
bool check_near(char a,char b){
	if(b<a)swap(a,b);
	if(a=='A'){
		if(b=='B')return true;
	}
	if(a=='B'){
		if(b=='C')return true;
	}
	if(a=='D'){
		if(b=='F')return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>x1>>x2>>y1>>y2;
	if(x1!=y1){
		cout<<"0000\n";
		return 0;
	}
	x3=x2[2],y3=y2[2];
	x2=x2.substr(0,2);y2=y2.substr(0,2);
	if(x2!=y2){
		cout<<"1000\n";
		return 0;
	}
	if(!check_side(x3,y3)){
		cout<<"1100\n";
		return 0;
	}
	if(!check_near(x3,y3)){
		cout<<"1110\n";
		return 0;
	}
	cout<<"1111\n";
	return 0;
}
