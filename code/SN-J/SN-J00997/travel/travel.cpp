#include<bits/stdc++.h>
using namespace std;
int rx,rz,xx,xz;
char rzz,xzz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		int x;
		int z;
		char zz;
		cin>>x;
		cin>>z>>zz;
		if(i==1){
		   rx=x;
		   rz=z;
		   rzz=zz;
		}
		else if(i==2){
		   xx=x;
		   xz=z;
		   xzz=zz;
	    }
	}
	int re=int(rzz);
	int xe=int(xzz);
	if(rx==xx){
		cout<<1;
	} 
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	if(rz==xz)
	{
		cout<<1;
	 } 
	else{
		cout<<0<<0<<0;
		return 0;
	} 
	if(rz==xz){
		if((65<=re&&re<=67)&&(65<=xe&&xe<=67)){
			cout<<1;
		}
		if(68==re&&xe==69){
			cout<<1<<1;
			return 0;
		}
		else{
		cout<<0<<0;
		return 0;
		} 
	}
	else{
		cout<<0<<0;
		return 0;
	} 
	if(((xe!=67||xe!=68)&&(re!=67||re!=68))&&abs(re-xe)==1){
		cout<<1;
	} 
	else {
		cout<<0;
	}
	return 0;
}
