#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char b[3]={},d[3]={};
	int a,c;
	cin>>a>>b[1]>>b[2]>>b[3]>>c>>d[1]>>d[2]>>d[3];
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	if(b[1]!=d[1]||b[2]!=d[2]){
		cout<<"1000";
		return 0;
	}
	if(b[3]<='C'&&d[3]>='D'){
		cout<<"1100";
		return 0;
	}
	if(b[3]>='D'&&d[3]<='C'){
		cout<<"1100";
		return 0;
	}
	if(b[3]-d[3]==1||b[3]-d[3]==-1&&b[3]!='C'&&d[3]!='C'){
		cout<<"1111";
		return 0;
	}
	else {
		cout<<"1110";
		return 0;
	}
}