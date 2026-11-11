#include<bits/stdc++.h>
using namespace std;
int n(char s){
	if(s=='D'||s=='F')return 1;
	else return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,c,ch,h;
	cin>>s>>c>>ch>>h;
	if(s==ch){
		cout<<1; 
		if(c[0]==h[0]&&c[1]==h[1]){ 
			cout<<1;
			if(n(c[2])==n(h[2])){
				cout<<1;
				if(c[2]-'A'==h[2]-'A'+1||c[2]-'A'==h[2]-'A'-1)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0; 
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
