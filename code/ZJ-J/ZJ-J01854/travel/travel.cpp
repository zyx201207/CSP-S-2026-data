#include<bits/stdc++.h>
using namespace std;
#define int long long 
int x1,x2,x3,x4;
char c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x3>>c1>>x2>>x4>>c2;
	if(x1!=x2){
		cout<<"0000";
		return 0;
	}
	if(x3!=x4){
		cout<<"1000";
		return 0;
	}
	if(c1<='C'&&c2>='D'){
		cout<<"1100";
		return 0;
	}
	if(c1>='D'&&c2<='C'){
		cout<<"1100";
		return 0;
	}
	if((c1=='A'&&c2=='B')||(c1=='B'&&c2=='A')){
		cout<<"1111";
		return 0;
	}
	if((c1=='B'&&c2=='C')||(c1=='C'&&c2=='B')){
		cout<<"1111";
		return 0;
	}
	if((c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}