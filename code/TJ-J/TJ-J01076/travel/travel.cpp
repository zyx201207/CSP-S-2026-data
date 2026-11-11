#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int f=0;
	for(int i=0;i<2;i++){
		if(s1[i]!=s3[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<2;i++){
		if(s2[i]!=s4[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if(s2[2]=='D'||s2[2]=='E')f++;
	if(s4[2]=='D'||s4[2]=='E')f++;
	if(f==1){
		cout<<00;
		return 0;
	}
	cout<<1;
	if(s2[2]==s4[2]){
		cout<<0;
		return 0;
	}
	if(f==2){
		cout<<1;
		return 0;
	}
	if(s2[2]=='A'&&s4[2]=='C'||s2[2]=='C'&&s4[2]=='A'){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
