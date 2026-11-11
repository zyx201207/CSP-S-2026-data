#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a1,b1,a2,b2;
    int a,b,c,d;
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2){
    	a=1;
    	if(b1[0]==b2[0]&b1[1]==b2[1]){
    		b=1;
    		if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'){
    			if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
    				c=1;
    				if(b1[2]=='A'&&b2[2]=='C') d=0;
    				else if(b2[2]=='A'&&b1[2]=='C') d=0;
    				else d=1;
    				cout<<a<<b<<c<<d;
				}
				else{
					c=0;
					d=0;
					cout<<a<<b<<c<<d;
					return 0;
				}
			}
			else if(b1[2]=='D'||b1[2]=='F'){
				if(b2[2]=='D'||b2[2]=='F'){
    				c=1;
    				d=1;
    				cout<<a<<b<<c<<d;
				}
				else{
					c=0;
					d=0;
					cout<<a<<b<<c<<d;
					return 0;
				}
			}
			}
		
		else{
			b=0;
			c=0;
			d=0;
			cout<<a<<b<<c<<d;
			return 0;
		}
	}
	else{
		a=0;
		b=0;
		c=0;
		d=0;
		cout<<a<<b<<c<<d;
	}
	
	return 0;
} 

