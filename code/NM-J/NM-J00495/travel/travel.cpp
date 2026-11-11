#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	vector<char>s1,s2;
	string c1,c2;
	int k=0;
	cin>>c1;
	for(int i=0;i<3;i++){
		char t='\0';
		cin>>t;
		s1.push_back(t);
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		char t='\0';
		cin>>t;
		s2.push_back(t);
	}
	if(c1==c2){
		cout<<1;
		if(s1[k]==s2[k]&&s1[k+1]==s2[k+1]){
			cout<<1;
			k=2;
			if(s1[k]=='A'||s1[k]=='B'||s1[k]=='C'&&s2[k]=='A'||s2[k]=='B'||s2[k]=='C'){
				cout<<1;
			}else if(s1[k]=='D'||s1[k]=='F'&&s2[k]=='D'||s2[k]=='F'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0;
		}
	
	}else{
		cout<<0<<0<<0;
	}	
	if(s1[k]=='A'&&s2[k]=='B'){
		cout<<1;
	}else if(s1[k]=='B'&&s2[k]=='C'){
		cout<<1;
	}else if(s1[k]=='D'&&s2[k]=='F'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

