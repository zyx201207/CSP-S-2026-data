#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int c1,s1,c2,s2;
	cin>>c1>>s2>>c2>>s2;
	if(c1==16 or c1==01){
		cout<<0;
	}
	else{
		cout<<1;
		if(c1==c2){
		    cout<<1;
	    }
	    else{
		    cout<<0;
	    }
    }
	if(18>s1>01){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1==s2){
		cout<<0;
	}
	else{
		cout<<1;
	}
	
	return 0;
}

