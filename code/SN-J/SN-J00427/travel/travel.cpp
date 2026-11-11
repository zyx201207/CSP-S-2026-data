#include <bits/stdc++.h>
using namespace std;
string ax,az,bx,bz;
bool c=0,d=0;
bool s=0,x=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>ax>>az>>bx>>bz;
	
	int za=az[2];
	int zb=bz[2];
	if(ax[0]==bx[0]&&ax[1]==bx[1]){
		c=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(c==1&&az[0]==bz[0]&&az[1]==bz[1]){
		d=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(c==1&&za<68&&zb<68&&d==1){
		x=1;
		cout<<"1";
	}else if(c==1&&za>=68&&zb>=68&&d==1){
		s=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c==1&&d==1){
		if(s==1){
			cout<<"1";
		}else if(x==1&&(za+zb)!=132){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
}

