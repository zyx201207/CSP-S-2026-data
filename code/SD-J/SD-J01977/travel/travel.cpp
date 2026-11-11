#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1.size()!=c2.size()){
		cout<<"0000";
		return 0;
	}
	else{
		for(int i=0;i<c1.size();i++){
			if(c1[i]!=c2[i]){
				cout<<"0000";
				return 0;
			}
		}
		cout<<"1";
		if(s1.size()!=s2.size()){
			cout<<"000";
			return 0;
		}
		else{
			for(int i=0;i<s1.size()-1;i++){
				if(s1[i]!=s2[i]){
					cout<<"000";
					return 0;
				}
			}
			cout<<1;
		}
		if(s1[s1.size()-1]=='F'&&s2[s2.size()-1]!='D'||s1[s1.size()-1]=='D'&&s2[s2.size()-1]!='F'){
			cout<<"00";
			return 0;
		}
		if((s1[s1.size()-1]=='A'||s1[s1.size()-1]=='B'||s1[s1.size()-1]=='C')&&(s2[s2.size()-1]!='A'&&s2[s2.size()-1]!='B'&&s2[s2.size()-1]!='C')){
			cout<<"00";
			return 0;
		}
		cout<<"1";
		if(s1[s1.size()-1]=='A'&&s2[s2.size()-1]!='B'){
			cout<<"0";
			return 0;
		}
		if(s1[s1.size()-1]=='B'&&s2[s2.size()-1]!='A'&&s2[s2.size()-1]!='C'){
			cout<<"0";
			return 0;
		}
		if(s1[s1.size()-1]=='C'&&s2[s2.size()-1]!='B'){
			cout<<"0";
			return 0;
		}
		cout<<1;
	}
	return 0;
}
