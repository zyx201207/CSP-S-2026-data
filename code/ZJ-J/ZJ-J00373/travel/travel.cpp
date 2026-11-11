#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	int flag=1;
	for(int i=0;i<=1;i++){
		if(a1[i]!=b1[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<=1;i++){
		if(a2[i]!=b2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if(a2[2]=='A'&&a2[2]=='B'||b2[2]=='C') cout<<1;
	else if(a2[2]=='B'&&b2[2]=='A'||b2[2]=='C') cout<<1;
	else if(a2[2]=='C'&&b2[2]=='A'||b2[2]=='B') cout<<1;
	else if(a2[2]=='D'&&b2[2]=='F'){
		cout<<"11";
		return 0;
	}
	else if(a2[2]=='F'&&b2[2]=='D'){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(a2[2]=='A'&&b2[2]=='B') cout<<1;
	else if(a2[2]=='B'&&b2[2]=='A'||b2[2]=='C') cout<<1;
	else if(a2[2]=='C'&&b2[2]=='B') cout<<1;
	else cout<<0;
	return 0;
}