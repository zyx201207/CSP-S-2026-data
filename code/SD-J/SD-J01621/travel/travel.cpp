#include<bits/stdc++.h>
using namespace std;
string x,r,xh,rh; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>xh>>r>>rh;
	if(x!=r){
		cout<<0<<0<<0<<0;
		return 0;
	}else{
		cout<<1;
	}
	if(xh[0]==rh[0]&&xh[1]==rh[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(xh[2]<='C'&&rh[2]<='C'||xh[2]>='D'&&rh[2]>='D'){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(xh[2]+1==rh[2]&&xh[2]!='C'||xh[2]-1==rh[2]&&xh[2]!='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

