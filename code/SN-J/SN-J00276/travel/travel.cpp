#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f=false;
	for(int i=0;i<c1.size();i++){
		if(c1[i]==c2[i]) f=true;
		else{
			cout<<"0"<<"0"<<"0"<<"0";
			f=false;
			break;
		}
	}
	if(f==true){
		cout<<"1";
		f=false;
		for(int i=0;i<s1.size()-1;i++){
			if(s1[i]==s2[i]) f=true;
			else{
				cout<<"0"<<"0"<<"0";
				f=false;
				break;
			}
		}
		if(f==true){
			cout<<"1";
			if(s1[s1.size()-1]=='A'||s1[s1.size()-1]=='B'||s1[s1.size()-1]=='C'){
				if(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='B'||s2[s2.size()-1]=='C') cout<<"1";
				else cout<<"0";
			}
			else{
				if(s2[s2.size()-1]=='D'||s2[s2.size()-1]=='F') cout<<"1";
				else cout<<"0";
			}
			f=false;
			if(s1[s1.size()-1]=='A'){
				if(s2[s2.size()-1]=='B')cout<<"1";
				else cout<<"0";
			}
			if(s1[s1.size()-1]=='B'){
				if(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='C')cout<<"1";
				else cout<<"0";
			}
			if(s1[s1.size()-1]=='C'){
				if(s2[s2.size()-1]=='B')cout<<"1";
				else cout<<"0";
			}
			if(s1[s1.size()-1]=='D'){
				if(s2[s2.size()-1]=='F')cout<<"1";
				else cout<<"0";
			}
			if(s1[s1.size()-1]=='F'){
				if(s2[s2.size()-1]=='D')cout<<"1";
				else cout<<"0";
			}
		} 
	} 
	return 0;
}
