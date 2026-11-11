#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1;
	cin>>m>>s2;
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}
	
	int a1=s1[0],a2=s1[1];
	char a3=s1[2];
	int b1=s2[0],b2=s2[1];
	char b3=s2[2];
	if(a1!=b1||a2!=b2){
		cout<<"000";
		return 0;
	}
	else {
		cout<<1;
	}
	if((a3=='C'&&b3=='D'||a3=='D'&&b3!='C')){
		cout<<"00";
		return 0;
	}
	else {
		cout<<1;
	}
	if(a3-b3==1||b3-a3==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
