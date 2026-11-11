#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>c2>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[0]=='A'&&s1[1]!='A'||s1[0]=='B'&&s1[1]!='B'||s1[0]=='C'&&s1[1]!='C'||s1[0]=='D'&&s1[1]!='D'||s1[0]=='F'&&s1[1]!='F'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[0]>='A'&&s2[0]>='B'||s1[0]>='B'&&s2[0]>='C'||s1[0]>='D'&&s2[0]>='F'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int n=18;
	while(n==0){
		if(s1[0]>=n&&s2[0]>=n+1){
			cout<<"1";
			break;
		}
		n--; 
	}
	for(int i=0;i<n;i++){
		if(s1[0]!=n&&s2[0]!=n+1){
		cout<<"0";
		return 0;
		}
	}
	return 0;
}
