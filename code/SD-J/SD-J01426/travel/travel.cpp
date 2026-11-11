#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s,s1,s2,s3,s4;
	getline(cin,s);
	s1=s.substr(0,2);
	s2=s.substr(3,3);
	s3=s.substr(7,2);
	s4=s.substr(10,3);
	if(s1==s3){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==s3&&s2[0]+s2[1]==s4[0]+s4[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==s3&&s2[0]+s2[1]==s4[0]+s4[1]){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'){
				cout<<1;
		    }else{
		    	cout<<0;
			}
		}else{
			if(s2[2]=='D'||s4[2]=='F'){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	if(s1==s3&&s2[0]+s2[1]==s4[0]+s4[1]){
		if(s2[2]=='A'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='A'){
			cout<<1;
		}else if(s2[2]=='B'&&s4[2]=='C'||s2[2]=='C'&&s4[2]=='B'){
			cout<<1;
		}else if(s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	} 
	return 0;
}
