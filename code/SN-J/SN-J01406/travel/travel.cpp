#include<bits/stdc++.h>
using namespace std;
int c1,c2,s11,s22;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s11>>s1;
	cin>>c2;
	cin>>s22>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(s11==s22){
	    cout<<1;
	}else{
	    cout<<"000";
	    return 0;
	}
	
	if((s1>='A'&&s1<='C')&&(s2>='A'&&s2<='C')){
		cout<<1;
		
	if(s1+1==s2||s1-1==s2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	}else if((s1>='D'&&s1<='F')&&(s2>='D'&&s2<='F')){
		cout<<1;
		
	if(s1+1==s2||s1-1==s2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	}else{
		cout<<"00";
	}
	return 0;
}
