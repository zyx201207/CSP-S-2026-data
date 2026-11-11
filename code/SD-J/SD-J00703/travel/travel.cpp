#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s3[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<=1;i++){
		if(s2[i]!=s4[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if((s2[2]<'D'&&s4[2]<'D')||(s2[2]>'C'&&s4[2]>'C')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	int n=abs(s2[2]-s4[2]);
	if(n==1){
		cout<<"1";
	}
	else if(n==2){
		if((s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
} 
