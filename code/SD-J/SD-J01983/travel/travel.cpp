#include<bits/stdc++.h>
using namespace std;
string s,sp,c,cp;
bool flag,flagg,flaggg,flagggg;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>sp>>c>>cp;
	int f=int(abs(int(sp[2]-cp[2])));
	if(s==c){
		cout<<1;
		flag=1;
	}
	else{
		cout<<0;
	}
	if(sp[1]==cp[1]&&sp[0]==cp[0]&&flag==1){
		cout<<1;
		flagg=1;
	}
	else{
		cout<<0;
	}
	if(flag==1&&flagg==1&&((sp[2]<='C'&&cp[2]<='C')||(sp[2]>'C'&&cp[2]>'C'))){
		cout<<1;
		flaggg=1;
	}
	else{
		cout<<0;
	}
	if(flag==1&&flagg==1&&flaggg==1&&f==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
