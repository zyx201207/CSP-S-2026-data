#include<bits/stdc++.h>
using namespace std;
#define PIN freopen("travel.in","r",stdin);
#define POUT freopen("travel.out","w",stdout);
int main(){
	PIN;POUT;
	string bp,dp,a,c;bool pd=false;
	char bx,by,dx,dy;
	cin>>a>>bx>>by>>bp>>c>>dx>>dy>>dp;
	if(a!="01" && a!="16"&& c!="01" && c!="16"){
		if(a==c){
			cout<<1;
			pd=true;
		}else{
			cout<<0;
			pd=false;
		}
	}else{
		cout<<0;
		pd=false;
	}
	
	
	//cout<<9<<endl;
	if(pd==true){
		//cout<<bx<<" "<<dx<<" "<<dy<<" "<<by<<" ";
		if(by==dy && dx==bx){
			cout<<1;
		}else{
			cout<<0;
			pd=false;
		}
	}else{
		cout<<0;
		pd=false;
	}
	
	//cout<<1<<endl;
	if(pd==true){
		if(bp=="C" && dp=="D"){
			cout<<0;
			pd=false;
		}else if(bp=="D"&& dp=="C"){
				cout<<0;
				pd=false;
			}else{
				cout<<1;
				pd=true;
			}
	}else{
		cout<<0;
	}
	
	//cout<<7<<endl;
	if(pd==true){
		//cout<<bz<<" "<<dz<<" ";
		if(bp=="A" && dp=="B"){
			cout<<1;
		}else if(bp=="B" && dp=="A"){
			cout<<1;
		}else if(dp=="C"){
			cout<<1;
		}else if(bp=="C" && dp=="B"){
			cout<<1;
		}else if(bp=="D" && dp=="F"){
			cout<<1;
		}else if(bp=="F" && dp=="D"){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	//cout<<8<<endl;
	return 0;
} 
