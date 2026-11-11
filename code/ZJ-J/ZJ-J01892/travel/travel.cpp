#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1[0] != b1[0] || a1[1] != b1[1]){
		cout<<"0000";
	}
	else if(a2[0] != b2[0] || a2[1] != b2[1]){
		cout<<"1000";
	}
	else if(a2[2]<='C' && b2[2]<='C'){
		if(a2[2] == 'B' || b2[2] == 'B') cout<<"1111";
		else cout<<"1110";
	}
	else if(a2[2]>'C' && b2[2]>'C') cout<<"1111";
	else cout<<"1100";
	return 0;
}