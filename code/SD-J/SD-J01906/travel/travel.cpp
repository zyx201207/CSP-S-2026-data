#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		string ss1="";
		ss1+=s1[0];
		ss1+=s1[1];
		string ss2="";
		ss2+=s2[0];
		ss2+=s2[1];
		if(ss1!=ss2){
			cout<<"000";
		}else{
			cout<<"1";
			bool flag1=0,flag2=0;
			if(s1[2]>'C'){
				flag1=1;
			}if(s2[2]>'C'){
				flag2=1;
			}if(flag1!=flag2){
				cout<<"00";
			}else{
				cout<<"1";
				if(flag1||abs(s1[2]-s2[2])==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
	}return 0;
} 
