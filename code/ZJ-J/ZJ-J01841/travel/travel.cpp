#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r2,x2;int r1,x1;
	cin>>r1>>r2>>x1>>x2;
	if(r1!=x1){
		cout<<"0000"<<endl;
		return 0;
	}cout<<1;
	if((r2[0]!=x2[0]) || (r2[1]!=x2[1])){
		cout<<"000"<<endl;
		return 0;
	}cout<<1;
	int r3,x3;
	if((r2[2]=='A')||(r2[2]=='B')||(r2[2]=='C')) r3=1; else r3=0;
	if((x2[2]=='A')||(x2[2]=='B')||(x2[2]=='C')) x3=1; else x3=0;
	if(r3!=x3){
		cout<<"00"<<endl;
		return 0;
	}cout<<1;
	if(((x2[2]=='A')&&(r2[2]=='C'))||((x2[2]=='C')&&(r2[2]=='A'))){
		cout<<0;
	}else cout<<1;
	cout<<endl;
	return 0;
}