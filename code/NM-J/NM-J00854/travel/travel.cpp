#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if(a<='C'&&a>='A'&&b<='C'&&b>='A'){
		return true;
	}
	if((a=='D'||a=='E')&&(b=='D'||b=='E')){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s,s1;
	cin>>a>>s>>b>>s1;
	if(a==b){
		cout<<1;
		if(s[0]==s1[0]&&s[1]==s1[1]){
			cout<<1;
			char aa,bb;
			aa=s[2],bb=s1[2];
			if(check(aa,bb)){
				cout<<1;
				if(aa+1==bb||aa-1==bb){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
