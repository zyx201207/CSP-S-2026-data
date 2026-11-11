#include<bits/stdc++.h>
using namespace std;
bool check(char x,char y){
	if(x>y) swap(x,y);
	if((x<='C')&&('D'<=y)){
		return false;
	}else{
		return true;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	string s="",t="";
	for(int i=0;i<2;i++){
		s+=s1[i];
		t+=s2[i];
	}
	if(s==t){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(check(s1[2],s2[2])){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
