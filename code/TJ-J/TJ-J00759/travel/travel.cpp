#include <bits/stdc++.h>
using namespace std;
int f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c2,s2;
	cin>>c>>s>>c2>>s2;
	for(int i=0;i<c.size();i++){
		if(c[i]!=c2[i]){
			cout<<0<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]!=s2[i]){
			cout<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	int a,b;
	if(s[s.size()-1]=='A'||s[s.size()-1]=='B'||s[s.size()-1]=='C'){
		a=1;
	}
	else a=2;
	if(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='B'||s2[s2.size()-1]=='C'){
		b=1;
	}
	else b=2;
	if(a==b) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(s[s.size()-1]+1==s2[s2.size()-1]) cout<<1;
	else if(s2[s2.size()-1]+1==s[s.size()-1]) cout<<1;
	else if(a==2&&b==2&&s[s.size()-1]+2==s2[s2.size()-1]) cout<<1;
	else if(a==2&&b==2&&s2[s2.size()-1]+2==s[s.size()-1]) cout<<1;
	else cout<<0;
	return 0;
} 
