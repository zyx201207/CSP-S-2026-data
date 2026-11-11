#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0] && a2[1]==b2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char q,w;
	q=a2[2];
	w=b2[2];
	if(q<='C' && w<='C'){
		cout<<1;
		if(q-w==1 || w-q==1){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(q>='D' && w>='D'){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
	}
	return 0;
}
