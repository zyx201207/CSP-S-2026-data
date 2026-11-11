#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int zuo=-1,you=-1;
bool qu1=false,qu2=false,qu3=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<'1';
		qu1=true;
	}else{
		cout<<'0';
	}
	if(sr[0]==sx[0]&&sr[1]==sx[1]){
		if(qu1){
			cout<<'1';
			qu2=true;
		}else{
			cout<<'0';
		}
	}else{
		cout<<'0';
	}
	if(sr[2]>='A'&&sr[2]<='C'){
		zuo=1;
	}
	if(sx[2]>='A'&&sx[2]<='C'){
		you=1;
	}
	if(zuo==you){
		if(qu2){
			cout<<'1';
			qu3=true;
		}else{
			cout<<'0';
		}
	}else{
		cout<<'0';
	}
	if(abs(sr[2]-sx[2])==1){
		if(qu3){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}else{
		cout<<'0';
	}
	return 0;
}
