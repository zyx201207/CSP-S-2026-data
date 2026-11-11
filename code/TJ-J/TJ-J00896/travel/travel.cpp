#include<bits/stdc++.h>
using namespace std;
char c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(int(c2-c4)==1||int(c4-c2)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if((int(c2-c4)==1||int(c4-c2)==1)&&(c2<='c'&&c2-c4==1)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(int(c2-c4)==1||int(c4-c2)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
