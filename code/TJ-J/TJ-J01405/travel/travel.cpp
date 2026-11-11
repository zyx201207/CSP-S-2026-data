#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
		return 0;
	}else{
		if(s1[1]!=s2[1]){
			cout<<"1000";
			return 0;
		}else{
			if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='D'&&s2[2]=='E'||s1[2]=='E'&&s2[2]=='D'){
				if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
					cout<<"1110";
					return 0;
				}else{
					cout<<"1111";
					return 0;
				}
			}else{
				cout<<"1100";
				return 0;
			}
		}
	}
	return 0;
}
