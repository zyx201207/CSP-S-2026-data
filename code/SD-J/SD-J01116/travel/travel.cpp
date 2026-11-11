#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a2,b,b2;
	cin>>a>>a2>>b>>b2;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0] and a2[1]==b2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	int x,y;
	if(a2[2]>='A' and a2[2]<='C'){
		x=1;
	}
	else{
		x=0;
	}
	if(b2[2]>='A' and b2[2]<='C'){
		y=1;
	}
	else{
		y=0;
	}
	if(x==y) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(int(a2[2])-int(b2[2]))==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
