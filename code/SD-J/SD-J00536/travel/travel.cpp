#include <bits/stdc++.h>
using namespace std;
int a(string c){
	return c[2]-'A';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}else{
		cout<<1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(a(s1)+a(s2)==4||a(s1)+a(s2)==5){
		cout<<0<<0;
		return 0;
	}else{
		cout<<1;
	}
	if(a(s1)-a(s2)==1||a(s1)-a(s2)==-1){
		cout<<1;
	}else{
		cout<<0;
	}
	
	 
	return 0;
}
