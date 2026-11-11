#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<"1";
		char ca1=s1[2];
		char ca2=s2[2];
		int fabc1=0;
		int fabc2=0;
		if(ca1=='A' or ca1=='B' or ca1=='C'){
			fabc1=1;
		}
		if(ca2=='A' or ca2=='B' or ca2=='C'){
			fabc2=1;
		}
		if(fabc1!=fabc2){
			cout<<"00";
			return 0;
		}
		cout<<"1";
		if(fabc1==0){
			cout<<"1";
			return 0;
		}
		if(ca1=='C' and ca2=='A'){
			cout<<"0";
			return 0;
		}
		else if(ca1=='A' and ca2=='C'){
			cout<<"0";
			return 0;
		}
		cout<<"1";
		return 0; 
	}
	else{
		cout<<"0000";
	}
	return 0;
}
