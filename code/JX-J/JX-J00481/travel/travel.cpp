#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0]&&a1[1]==b1[1]){
		cout<<'1';
	}else{ 
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<'1';
	}else{ 
		cout<<"000";
		return 0;
	}
	if(a2[2]>='D'&&b2[2]>='D'){
		cout<<"11";
		return 0;
	}else if(a2[2]<='C'&&b2[2]<='C'){
		cout<<'1';
	}else{ 
		cout<<"00";
		return 0;
	}
	if(int(a2[2])+1==int(b2[2])||int(a2[2])-1==int(b2[2])){
		cout<<'1';
	}else cout<<'0';
	return 0;
}
