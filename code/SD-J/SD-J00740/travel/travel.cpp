#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,ce1="ABC",ce2="DF";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		if(s1.substr(0,2)!=s2.substr(0,2)){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				cout<<1;
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;					
				}
			}else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
				cout<<"11";
				return 0;
			}else{
				cout<<"00";
				return 0;
			}
		}
	}	
	return 0;
} 
