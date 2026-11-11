#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c;
	string s;
	string c1;
	string s1;
	cin>>c>>c1>>s>>s1;
	if(c==c1){
	cout<<1;
	}
	else{
	cout<<0;
	}
	string s2=s.substr(1,2);
	string s3=s1.substr(1,2);
	if(s2==s3){
	cout<<1;
	}
	else{
		cout<<0;
	}
		int a=s.substr(3,3);
		int b=s.substr(3,3);
		if(a>='A'&&a<='C'&&B>='A'&&B<='C'||a>='D'&&a<='F'a>='D'&&a<='F'){
		cout<<1;
		}
		else{
		cout<<0;
		}
		if(a-'0'-1==b||a-'0'+1==b&&a!=D&&A!='Z'){
			cout<<1;
		}
		else{}
		if(a=='D'&&b=='F'||a=='C'&&b=='B'){
		cout<<1;
		}
		
		else{
		 cout<<0;
		}
return 0;
}
