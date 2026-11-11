#include<bits/stdc++.h>
using namespace std;
string s,s1;
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s>>m>>s1;
	if(n!=m){
		cout<<"0000";
		return 0;
	}if(s[0]+s[1]!=s1[0]+s1[1]){
		cout<<"1000";
		return 0;
	}
	char c=s[2],c1=s1[2];
	char f=max((int)c,(int)c1),f1=min((int)c,(int)c1);
	if((f=='F'&&f1=='D')||f<='C'){
		if(f-1==f1){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1110";
			return 0;
		}
	}else{
		cout<<"1100";
		return 0;
	}
	return 0;
} 
