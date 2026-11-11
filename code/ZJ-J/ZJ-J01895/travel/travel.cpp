#include<bits/stdc++.h>
using namespace std;
int c,cc;
string s,ss,s1,ss1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		cout<<0<<0<<0<<0;
	}
	else{
		cout<<1;
		s1=s[0]; s1+=s[1];
		ss1=ss[0]; ss1+=ss[1];
		if(s1!=ss1){
			cout<<0<<0<<0;
		}
		else{
			cout<<1;
			if(s[2]=='A'&&(ss[2]=='B'||ss[2]=='C')){
				cout<<1;
				if(ss[2]=='B'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(s[2]=='B'&&(ss[2]=='A'||ss[2]=='C')){
				cout<<1<<1;
			}
			else if(s[2]=='C'&&(ss[2]=='B'||ss[2]=='A')){
				cout<<1;
				if(ss[2]=='B'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(s[2]=='D'&&ss[2]=='F'){
				cout<<1<<1;
			}
			else if(s[2]=='F'&&ss[2]=='D'){
				cout<<1<<1;
			}
			else{
				cout<<0<<0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}