#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>t1>>t2;
	int m1=s2[2];
	int m2=t2[2];
    if(s1==t1){
	    cout<<1;
		if(s2[0]==t2[0] && s2[1]==t2[1]){
			cout<<1;
			if(m1<=67 && m2<=67 || m1>=68&& m2>=68){
				cout<<1;
	        	if( (m1-m2==1) || (m2-m1==1) ){
					cout<<1;
				}else if(m1>=68&&m2>=68){cout<<1;}
	        	else{cout<<0;}
	    	}
	    	else{cout<<0<<0;}
		}
	    else {cout<<0<<0<<0;}
	}
    else {cout<<0<<0<<0<<0;}
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
