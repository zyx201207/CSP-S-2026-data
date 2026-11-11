#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n;
	string s1,s2;
	cin>>m>>s1>>n>>s2;
	if(m!=n){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int sline=0;
	char c1=s1[0],c2=s2[0];
	char d1=s1[1],d2=s2[1];
	char e1=s1[2],e2=s2[2];
	if(c1==c2&&d1==d2){
		cout<<1;
		sline=1;
	}
	else{
		cout<<"000";
		return 0;
	}
	int sside=0;
	if(e1=='A'||e1=='B'||e1=='C'){
		if(e2=='A'||e2=='B'||e2=='C'){
			cout<<1;
			sside=1;
		}
		else cout<<0;
	}
	if(e1=='D'||e1=='F'){
		if(e2=='D'||e2=='F'){
			cout<<1;
			sside=1;
		}
		else cout<<0;
	}
	if(sline==1&&sside==1){
		if(e1=='A'&&e2=='C'||e1=='C'&&e2=='A'){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}




