#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool isTC=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<0;
		isTC=false;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&isTC) cout<<1;
	else{
		cout<<0;
		isTC=false;
	}
	
	if(s1[2]=='A'){
		if(s2[2]=='A'&&isTC) cout<<1;
		else if(s2[2]=='C'&&isTC) cout<<1;
		else if(s2[2]=='B'&&isTC) cout<<1;
		else if(s2[2]=='D') {
			cout<<0;
//			isTC=false;
		}
		else if(s2[2]=='F') {
			cout<<0;
//			isTC=false;	
		}
		else{
			cout<<0;
//			isTC=false;
		} 
	}
	else if(s1[2]=='B'){
		if(s2[2]=='A'&&isTC) cout<<1;
		else if(s2[2]=='B'&&isTC) cout<<1;
		else if(s2[2]=='C'&&isTC) cout<<1;
		else if(s2[2]=='D'){
			cout<<0;
//			isTC=false;
		}
		else if(s2[2]=='F') {
			cout<<0;
//			isTC=false;
		}
		else{
			cout<<0;
//			isTC=false;
		} 
	}
	else if(s1[2]=='C'){
		
		if(s2[2]=='A'&&isTC) cout<<1;
		else if(s2[2]=='B'&&isTC) cout<<1;
		else if(s2[2]=='C'&&isTC) cout<<1;
		else if(s2[2]=='D'){
			cout<<0;
//			isTC=false;
		}
		else if(s2[2]=='F'){
			cout<<0;
//			isTC=false;
		}
		else{
			cout<<0;
//			isTC=false;
		} 
	}
	else if(s1[2]=='D'){
		if(s2[2]=='A'){
			cout<<0;
//			isTC=false;
		}
		else if(s2[2]=='B'){
			cout<<0;
//			isTC=false;
		}
		else if(s2[2]=='C'){
			cout<<0;
//			isTC=false;
		}
		else if(s2[2]=='D'&&isTC) cout<<1;
		else if(s2[2]=='F'&&isTC) cout<<1;
		else{
			cout<<0;
//			isTC=false;
		} 
	} 
	else if(s1[2]=='F'){
		if(s2[2]=='A'){
			cout<<0;
//			isTC=false;
		}
		else if(s2[2]=='B'){
			cout<<0;
//			isTC=false;
		}
		else if(s2[2]=='C'){
			cout<<0;
//			isTC=false;
		}
		else if(s2[2]=='D'&&isTC) cout<<1;
		else if(s2[2]=='F'&&isTC) cout<<1;
		else{
			cout<<0;
//			isTC=false;
		} 
	} 
	
	if(isTC){
		if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D')){
			cout<<0;
			return 0;
		}
		if(abs((s1[2]-'0')-(s2[2]-'0'))==1) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	
	
	
	return 0;
}
