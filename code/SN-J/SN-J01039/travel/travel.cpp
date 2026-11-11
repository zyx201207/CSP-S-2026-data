#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a,b,x,y;
    bool n=1;
    cin>>a>>x>>b>>y;
    if(a[0]==b[0]&&a[1]==b[1])
    {
    	cout<<"1";
	}else{
		cout<<"0";
		n=0;
	} 
	 if(x[0]==y[0]&&x[1]==y[1]&&n==1)
    {
    	cout<<"1";
	}else{
		cout<<"0";
		n=0;
	} 
	if(n==1)
    {
    	if(x[2]<='C'&&y[2]<='C'||x[2]>'C'&&y[2]>'C'){
	        cout<<"1";
	    }else{
	    	cout<<"0";
			n=0; 
		} 
	}else{
		cout<<"0";
		n=0;
	} 
	if(n==1){
		if(x[2]=='A'&&y[2]=='B'||x[2]=='B'&&y[2]=='A'||x[2]=='B'&&y[2]=='C'||x[2]=='C'&&y[2]=='B'||x[2]=='A'&&y[2]=='D'||x[2]=='F'&&y[2]=='F'||x[2]=='D'){
	        cout<<"1";
	    }else{
	    	cout<<"0"; 
		} 
	}else{
		cout<<"0";
	}
	return 0;
} 
