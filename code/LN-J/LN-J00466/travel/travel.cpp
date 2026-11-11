#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>s1>>s2>>c1>>c2;
    if(s1==c1){
    	cout<<'1';
    	string a=s2.substr(0,2);
    	string b=c2.substr(0,2);
    	if(a==b){
    		cout<<'1';
    		if((s2[2]<='C'&&c2[2]<='C')||(s2[2]>='D'&&s2[2]>='D')){
    			cout<<'1';
    			if((s2[2]+1==c2[2]&&s2[2]!='C')||(s2[2]-1==c2[2]&&s2[2]!='D')||(s2[2]=='F'&&s2[2]-2==c2[2])||(c2[2]=='F'&&c2[2]-2==s2[2])){
    				cout<<'1';
    			}else{
    				cout<<'0';
    			}
    		}else{
    			cout<<"00";
    		}
    	}else{
    		cout<<"000";
    	}
    }else{
    	cout<<"0000";
    }
    return 0;
}
