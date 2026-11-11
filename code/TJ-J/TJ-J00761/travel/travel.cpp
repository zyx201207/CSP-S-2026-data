#include<bits/stdc++.h>
#include<string>
using namespace std;
int a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,a,b;
	cin>>n>>m>>a>>b;
	if(n==a){
		a = 1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(m[0] == b[0]&&m[1] == b [1]){
		a = 1;
	}else{
		cout<<"1000";
		return 0;
	}
	if((m[2]<='C'&&b[2] <='C')||(m[2] <='E'&&m[2]>='D'&&b[2] <='E'&&b[2]>='D')){
		a = 1;
	}else{
		cout<<"1100";
		return 0;
	}
	if((m[2]-b[2]==1)||(b[2]-m[2] == 1)){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
}
