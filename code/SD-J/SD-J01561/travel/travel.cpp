#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string ch1,ch2;//ch1代表第一个车厢编号， ch2代表第二个车厢编号
	string se1,se2;//se1代表第一个座位号，se2代表第二个座位号 
	cin>>ch1>>se1>>ch2>>se2;
	if(ch1==ch2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(se1[0]==se2[0]&&se1[1]==se2[1]&&ch1==ch2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(se1[0]==se2[0]&&se1[1]==se2[1]&&ch1==ch2){
		if((se1[2]>='D'&&se2[2]<='F')||(se1[2]>='A'&&se2[2]<='C')){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(se1[0]!=se2[0]||se1[1]!=se2[1]||ch1!=ch2){
		cout<<"0";
		return 0;
	}
	if((se1[2]>='D'&&se2[2]<='F')){
		cout<<"1";
	}else{
		if((se1[2]<='F'&&se1[2]>='D'&&se2[2]<='C')||(se2[2]<='F'&&se2[2]>='D'&&se1[2]<='C')){
			cout<<"0";
			return 0;
		}else{
			if(char(se1[2]-1)==se2[2]||char(se1[2]+1)==se2[2]){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}
	return 0;
}
