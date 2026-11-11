#include<bits/stdc++.h>
using namespace std;
string a,b,ax,bx,k,k1,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>ax>>b>>bx;
	if(a==b){
		cout<<1;
		k=k+ax[0]+ax[1];
	    k1=k1+bx[0]+bx[1];
	    if(k==k1){
		    cout<<1;
		    if(ax[2]=='A'&&bx[2]=='B'){
		    	cout<<1<<1;
	    	}else if(ax[2]=='C'&&bx[2]=='B'){
	    		cout<<1<<1;
	    	}else if(ax[2]=='D'&&bx[2]=='F'){
	    		cout<<1<<1;
	    	}else if(ax[2]=='F'&&bx[2]=='D'){
	    		cout<<1<<1;
	    	}else if(ax[2]=='B'&&bx[2]=='A'){
	    		cout<<1<<1;
	    	}else if(ax[2]=='A'&&bx[2]=='C'){
	    		cout<<1<<0;
	    	}else if(ax[2]=='C'&&bx[2]=='A'){
	    		cout<<1<<0;
	    	}else if(ax[2]=='B'&&bx[2]=='C'){
	    		cout<<1<<1;
	    	}else{
	     		cout<<0<<0;
	    	}
	    }else{
	    	cout<<0<<0<<0;
    	}
 	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}