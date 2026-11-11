#include<bits/stdc++.h>
using namespace std;

int r1,x1,f=0;
string r2,x2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	
	cin>>r1>>r2>>x1>>x2;
	
	if(r1==x1){
		f=4;
		if(r2[1]==x2[1]){
			f=3;
			if((r2[2]<='C'&&x2[2]<='C')||(r2[2]>='D'&&x2[2]>='D')){
				f=2;
				if(x2[2]+1==r2[2] || x2[2]-1==r2[2]) f=1;
			}
		}
	}
	
	if(f==1) cout<<1111;
	else if(f==2) cout<<1110;
	else if(f==3) cout<<1100;
	else if(f==4) cout<<1000;
	else if(f==0) cout<<"0000";
	
	return 0;
}//Trick||Treat!
