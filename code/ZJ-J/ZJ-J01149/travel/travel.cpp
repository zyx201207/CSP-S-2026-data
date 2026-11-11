#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	if(b[1]!=d[1]){
		cout<<"1000";
		return 0;
	}
	bool f=((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'));
	if(!(f)){
		cout<<"1100";
		return 0;
	}
	if(f&&abs(int(b[2])-int(d[2]))!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
