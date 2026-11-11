#include<bits/stdc++.h>
using namespace std;
string s,ss,t,tt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>t>>tt;
	if(s[0]==t[0]&&s[1]==t[1]){
		cout<<"1";
		if(ss[0]==tt[0]&&ss[1]==tt[1]){
			cout<<"1";
			if(ss[2]=='A'&&tt[2]=='B'||ss[2]=='C'&&tt[2]=='B'||ss[2]=='D'&&tt[2]=='F'||ss[2]=='B'&&tt[2]=='A'||ss[2]=='B'&&tt[2]=='C'||ss[2]=='F'&&tt[2]=='D'){
				cout<<"11";
			}else if(ss[2]=='C'&&tt[2]=='A'||ss[2]=='A'&&tt[2]=='C'){
				cout<<"10";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
