#include<bits/stdc++.h>
using namespace std;
bool cl(char a){
	return a>='A'&&a<='C';
}
bool cr(char a){
	return a>='D'&&a<='F';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    char ch1,ch2;
    int t1,t2;
    cin>>c1>>s1>>c2>>s2;
    ch1=s1[2];ch2=s2[2];
    t1=(s1[0]-48)*10+(s1[1]-48);
    t2=(s2[0]-48)*10+(s2[1]-48);
	if(c1==c2)
    cout<<"1";
    else{
    	cout<<"0000";
    	return 0;
	}
    
	if(t1==t2)
    cout<<"1";
    else{
    	cout<<"000";
    	return 0;
	}
    
	if((cl(ch1)&&cl(ch2))||(cr(ch1)&&cr(ch2)))
    cout<<"1";
    else{
    	cout<<"00";
    	return 0;
	}
    
	if(cr(ch1)&&cr(ch2)||(ch1==ch2+1||ch2==ch1+1)&&!(cr(ch1)||cr(ch2)))
	cout<<"1";
	else
	cout<<"0";
	return 0;
}
