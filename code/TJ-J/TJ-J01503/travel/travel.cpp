#include<bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>cr>>sr>>cx>>sx;
	int f=0;
	if(cr==cx){
		cout<<1;
		f=1;
	}   
	else{
		cout<<0;
		f=0;
	}   
	
	if(f&&(sr[0]+sr[1]==sx[0]+sx[1])){
		 cout<<1;
		 f=1;
	}  
	else{
		cout<<0;
		f=0;	
	} 
	
	if(f&&((sr[2]<='C'&&sx[2]<='C')||(sr[2]>'C'&&sx[2]>'C'))){
		cout<<1;
		f=1;
	}    
	else{
		cout<<0;
		f=0;
	} 
	
	if(f&&sr[2]-sx[2]==1||sr[2]-sx[2]==-1){
		if((sr[2]=='D'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='D'))    cout<<0;
		
		else cout<<1;
	}   
	else cout<<0;
	
	return 0;
} 
