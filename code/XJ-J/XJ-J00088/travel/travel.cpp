#include<bits/stdc++.h>
using namespace std;
struct node{
	string c,s;
}; 
	node a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1].c>>a[1].s;
	cin>>a[2].c>>a[2].s;
	
	if(a[1].c==a[2].c){
		cout<<"1";		
		
	}		
	else{
		cout<<"0000";
		return 0;
	}
	
	if(a[1].s[0]+a[1].s[1]==a[2].s[0]+a[2].s[1]){
	cout<<"1";			
	}		
	else{
		cout<<"000";
		return 0;
	}
	
	if(a[1].s[2]=='A'&&a[2].s[2]=='B'
	||a[1].s[2]=='A'&&a[2].s[2]=='C'
	||a[1].s[2]=='B'&&a[2].s[2]=='A'
	||a[1].s[2]=='B'&&a[2].s[2]=='C'
	||a[1].s[2]=='C'&&a[2].s[2]=='A'
	||a[1].s[2]=='C'&&a[2].s[2]=='B'	
	||a[1].s[2]=='D'&&a[2].s[2]=='F'
	||a[1].s[2]=='F'&&a[2].s[2]=='D') cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if(a[1].s[2]=='A'&&a[2].s[2]=='B'
	||a[1].s[2]=='B'&&a[2].s[2]=='A'
	||a[1].s[2]=='B'&&a[2].s[2]=='C'
	||a[1].s[2]=='C'&&a[2].s[2]=='B'	
	||a[1].s[2]=='D'&&a[2].s[2]=='F'
	||a[1].s[2]=='F'&&a[2].s[2]=='D') cout<<"1";
	else cout<<"0";
	return 0;
}
