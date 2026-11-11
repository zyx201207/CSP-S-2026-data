#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    a1=" "+a1;
    a2=" "+a2;
    b1=" "+b1;
    b2=" "+b2;
    
    if(a1==b1){
    	cout<<1;
	}else{
		cout<<0;
	}
	
	if(a1!=b1){
		cout<<0<<0<<0;
		return 0;
	}else{
		
		if(a2[1]==b2[1]&&a2[2]==b2[2]){
			cout<<1;
		}else{
			cout<<0;
	    }
	    if(a2[1]!=b2[1]||a2[2]!=b2[2]){
	    	cout<<0<<0;
	    	return 0;
		}
		
		if( (a2[3]=='D'&&b2[3]=='F') || (a2[3]=='F'&&b2[3]=='D') || (a2[3]=='A'&&b2[3]=='B')||(a2[3]=='A'&&b2[3]=='C')||(a2[3]=='B'&&b2[3]=='C')||(a2[3]=='C'&&b2[3]=='A')||(a2[3]=='C'&&b2[3]=='B')||(a2[3]=='B'&&b2[3]=='A')) {
			cout<<1;
		} else{
			cout<<0;
		}  
		
		if((a2[3]=='D'&&b2[3]=='F')||(a2[3]=='F'&&b2[3]=='D')||(a2[3]=='A'&&b2[3]=='B')||(a2[3]=='B'&&b2[3]=='A')||(a2[3]=='B'&&b2[3]=='C')||(a2[3]=='C'&&b2[3]=='B')) {
			cout<<1; 
		}    else{
			cout<<0;
		}                                 
	}
    return 0;
}

