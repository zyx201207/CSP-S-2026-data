#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	if(a==b){
		cout<<1;
		if(s[0]==t[0]&&s[1]==t[1]){
			cout<<1;
			if(('A'<=s[2]&&s[2]<='C'&&'A'<=t[2]&&t[2]<='C')||('D'<=s[2]&&s[2]<='E'&&'D'<=t[2]&&t[2]<='D')){
				cout<<1;
				if(s[2]-1==t[2]||s[2]+1==t[2]){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0;
				cout<<0;
			}
		}
		else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}