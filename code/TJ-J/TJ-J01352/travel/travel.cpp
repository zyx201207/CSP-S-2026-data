#include <bits/stdc++.h>
using namespace std ;
struct cp{
	string cx ;
	string zw ;
} ;
int main(){
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
	cp a,b ;
	cin>>a.cx>>a.zw>>b.cx>>b.zw ;
	if(a.cx!=b.cx){
    	cout<<"0000" ;
    	return 0 ;
    }
    if(10*(a.zw[0]-48)+(a.zw[1]-48)!=10*(b.zw[0]-48)+(b.zw[1]-48)){
    	cout<<"1000" ;
    	return 0 ;
	}
	if(!((a.zw[2]=='A'&&b.zw[2]=='B')||(a.zw[2]=='A'&&b.zw[2]=='C')||(a.zw[2]=='B'&&b.zw[2]=='C')||(a.zw[2]=='D'&&b.zw[2]=='F')||(b.zw[2]=='A'&&a.zw[2]=='B')||(b.zw[2]=='A'&&a.zw[2]=='C')||(b.zw[2]=='B'&&a.zw[2]=='C')||(b.zw[2]=='D'&&a.zw[2]=='F'))){
		cout<<"1100" ;
		return 0 ;
	}
	if(!(a.zw[2]+1==b.zw[2]||a.zw[2]-1==b.zw[2])){
		cout<<"1110" ;
		return 0 ;
	}
	cout<<"1111" ;
	return 0 ;
}
