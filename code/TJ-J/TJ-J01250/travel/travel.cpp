#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cnt=0;
	if(c1==c2){
		cout<<1;
		cnt++;
	}
	else{
		cout<<0;
	}
	if(s1[1]==s2[1]&&c1==c2){
		cout<<1;
		cnt++;
	}
	else{
		cout<<0;
	}
	if(s1[1]==s2[1]&&c1==c2){
		
		
		if(s1[2]=='A'&&s2[2]=='B'){
			cout<<1;
			cnt++;
		}
		else if(s1[2]=='B'&&s2[2]=='A'){
			cout<<1;
			cnt++;
		}
		else if(s1[2]=='A'&&s2[2]=='C'){
			cout<<1;
			cnt++;
		}
		else if(s1[2]=='C'&&s2[2]=='A'){
			cout<<1;cnt++;
		}
		else if(s1[2]=='B'&&s2[2]=='C'){
			cout<<1;cnt++;
		}
		else if(s1[2]=='C'&&s2[2]=='B'){
			cout<<1;cnt++;
		}
		else if(s1[2]=='D'&&s2[2]=='F'){
			cout<<1;cnt++;
		}
		else if(s1[2]=='F'&&s2[2]=='D'){
			cout<<1;cnt++;
		}
		else if(s1[1]!=s2[1]&&c1!=c2){
			cout<<0;cnt++;
		}
		else if(s1[1]!=s2[1]&&c1==c2){
			cout<<0;
			cnt++;
		}
		else if(s1[1]==s2[1]&&c1!=c2){
			cout<<0;
			cnt++;
		}
		else if(s1[1]==s2[1]&&c1==c2){
			cout<<0;
		}
		}
	else{
		cout<<0;
	}
	
	
	
	
	
	
	if(s1[2]=='A'&&s2[2]=='B'&&c1==c2&&s1[1]==s2[1]){
			cout<<1;
			cnt++;
	}
	else if(s1[2]=='B'&&s2[2]=='A'&&c1==c2&&s1[1]==s2[1]){
			cout<<1;
			cnt++;
	}
	else if(s1[2]=='B'&&s2[2]=='C'&&c1==c2&&s1[1]==s2[1]){
			cout<<1;
			cnt++;
	}
	else if(s1[2]=='C'&&s2[2]=='B'&&c1==c2&&s1[1]==s2[1]){
			cout<<1;
			cnt++;
	}
	else if(s1[2]=='D'&&s2[2]=='F'&&c1==c2&&s1[1]==s2[1]){
			cout<<1;
			cnt++;
		}
	else if(s1[2]=='F'&&s2[2]=='D'&&c1==c2&&s1[1]==s2[1]){
			cout<<1;
			cnt++;
	}
	else{
		cout<<0;
	}
	
	
	
	
	return 0;
}

