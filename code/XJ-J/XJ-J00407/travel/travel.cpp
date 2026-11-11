#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
		if(s2[0]+s2[1]==s4[0]+s4[1]){
			cout<<"1";
			if('A'<=s2[2]<='C'&&'A'<=s4[2]<='C'||'D'<=s2[2]<='F'&&'D'<=s4[2]<='F'){
				cout<<"1";
				if(s2[2]+1==s4[2]||s4[2]+1==s2[2]){
					cout<<"1";
				}
				else{
					cout<<"0"; 
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
}
