#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int op;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(b[2]<'D'&&d[2]<'D'){
		cout<<1;
		op=1;
	}else if(b[2]>='D'&&d[2]>='D'){
		cout<<1;
		op=2;
	}else{
		cout<<"00";
		return 0;
	}
	if(b[2]-d[2]==op||b[2]-d[2]==-op){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
