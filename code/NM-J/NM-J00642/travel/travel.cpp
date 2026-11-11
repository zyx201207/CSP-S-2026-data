#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int c11,c22;
    if(c1[0]=='0') c11=c1[1]-48;
    else{
        c11=10+c1[1]-48;
    }
    if(c2[0]=='0') c22=c2[1]-48;
    else{
        c22=10+c2[1]-48;
    }
    string s11="",s22="";
    s11+=s1[0];
    s11+=s1[1];
    s22+=s2[0];
    s22+=s2[1];
    if(c11==c22){
    	cout<<1;
    	if(s11==s22){
    		cout<<1;
    		if(((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C')) || ((s1[2]>='D' && s1[2]<='F') &&( s2[2]>='D' && s2[2]<='F'))){
    			cout<<1;
    			if(s1[2]-1==s2[2] || s1[2]+1==s2[2]){
    				cout<<1;
				}else{
					cout<<"0";
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
