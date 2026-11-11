#include<bits/stdc++.h>
using namespace std;
int c1,s1,x,y;
string c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>c2>>s1>>s2;
	if(c1!=s1){
		cout<<"0000\n";
		return 0;
	}
	if(c2.substr(0,2)!=s2.substr(0,2)){
		cout<<"1000\n";
		return 0;
	}
	if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
		x=1;
	}else{
		x=2;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		y=1;
	}else{
		y=2;
	}
	if(x!=y){
		cout<<"1100\n";
		return 0;
	}
	if(abs(s2[2]-c2[2])!=1){
		cout<<"1110\n";
		return 0;
	}
	cout<<"1111\n";
	return 0;
}
