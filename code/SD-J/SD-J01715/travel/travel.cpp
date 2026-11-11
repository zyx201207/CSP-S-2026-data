#include<bits/stdc++.h>
using namespace std;
string Cr,Sr,Cx,Sx;
bool flag_1=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>Cr>>Sr>>Cx>>Sx;
	if(Cr==Cx){
		cout<<1;
		flag_1=1;
	}
	else{
		cout<<0;
		flag_1=0;
	}
	if(flag_1&&Sx[1]==Sr[1]&&Sx[0]==Sr[0]){
		cout<<1;
		flag_1=1;
	}
	else{
		cout<<0;
		flag_1=0;
	}
	if(flag_1&&Sr[2]<='C'&&Sx[2]<='C' || flag_1&&Sr[2]>'C'&&Sx[2]>'C'){
		cout<<1;
		flag_1=1;
	}
	else{
		cout<<0;
		flag_1=0;
	}
	if(flag_1&&Sr[2]+1==Sx[2]||Sr[2]-1==Sx[2]&&flag_1) cout<<1;
	else cout<<0;
	return 0;
}      
