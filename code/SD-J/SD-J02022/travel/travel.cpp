#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"000";
			return 0;
		}
		else{
			cout<<1;
			if(s1[2]>'C'&&s2[2]<='C'||s1[2]<='C'&&s2[2]>'C'){
				cout<<"00";
				return 0;
			}
			else{
				cout<<1;
				if(s1[2]>'D'&&s2[2]>'D'){
					cout<<1;
					
				}
				else if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
		}
	}
	return 0;
}
