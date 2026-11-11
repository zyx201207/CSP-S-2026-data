#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,n=0;//³µÏá 
	string s1,s2;//ÅÅ 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";//0
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";//0
			if(s1[2]>='A' && s1[2]<='C'){
				if(s2[2]>='A' && s2[2]<='C'){
					cout<<"1";//0
					n++;
				}else{
					cout<<"00";//0
				}
			}else{
				if(s2[2]>='D' && s2[2]<='F'){
					cout<<"1";//0
					n++;
				}else{
					cout<<"00";//0
				}
			}
		}else {
			cout<<"000";//0
		}
	}else {
		cout<<"0000";//0
	}
	if(n==1){
		if(s1[2]+1==s2[2] || s1[2]-1==s2[2]){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
} 
