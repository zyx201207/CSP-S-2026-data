#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool f=false,x=false,c=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		x=true;
	}
	else cout<<0;
	if(x&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		f=true;
	}
	else cout<<0;
	if(f&&x){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				c=true;
				cout<<1;
			}
			else cout<<0;
		}
		else if(s1[2]=='D'||s1[2]=='E'){
			if(s2[2]=='D'||s2[2]=='E'){
				cout<<1;
				c=true;
			}
			else cout<<0;
		}
		else cout<<0;
	}
	else cout<<0;
	if(f==true&&x==true&&c==true){
	if(s1[2]=='A'&&s2[2]=='B') cout<<1;
		else if(s1[2]=='B'&&s2[2]=='C') cout<<1;
		else if(s2[2]=='A'&&s1[2]=='B') cout<<1;
		else if(s2[2]=='B'&&s1[2]=='C') cout<<1;
		else if(s1[2]=='D'&&s2[2]=='E') cout<<1;
		else if(s1[2]=='E'&&s2[2]=='D') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}