#include<bits/stdc++.h>
using namespace std;
string a1,a2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2){
		cout<<"1";
		for(int i=0;i<=1;i++){
			if(s1[i]!=s2[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<"1";
		if(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C')cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
		if(s1[2]=='A'&&s2[2]=='B'||s2[2]=='A'&&s1[2]=='B'||s1[2]=='C'&&s2[2]=='B'||s2[2]=='C'&&s1[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
