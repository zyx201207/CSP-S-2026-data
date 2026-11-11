#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,ss1,ss2,s3,ss3;
	cin>>s1>>s2>>ss1>>ss2;
	if(s1==ss1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s2.size()-1;i++){
		s3+=s2[i];
	}
	for(int i=0;i<ss2.size()-1;i++){
		ss3+=ss2[i];
	}
	if(s3==ss3){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}int x=s2.size()-1,y=ss2.size()-1;
	if(s2[x]=='A'||s2[x]=='B'||s2[x]=='C'){
		if(ss2[y]=='A'||ss2[y]=='B'||ss2[y]=='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	else if(s2[x]=='F'||s2[x]=='D'){
		if(ss2[y]=='F'||ss2[y]=='D'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(s2[x]=='A'){
		if(ss2[y]=='B'){
			cout<<1;
		}else cout<<0;
	}
	else if(s2[x]=='B'){
		if(ss2[y]=='A'||ss2[y]=='C')cout<<1;
		else cout<<0;
	}
	else if(s2[x]=='C'){
		if(ss2[y]=='B')cout<<1;
		else cout<<0;
	}else if(s2[x]=='D'){
		if(ss2[y]=='F')cout<<1;
		else cout<<0;
	}
	else if(s2[x]=='F'){
		if(ss2[y]=='D')cout<<1;
		else cout<<0;
	}
	return 0;
}
