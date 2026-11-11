#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if((s[0]==ss[0])&&(s[1]==ss[1])){
		cout<<1;
		if((int(s[2])<=67&&int(s[2]>=65)&&int(ss[2])<=67&&int(ss[2]>=65))||(s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')){
			cout<<1;
			if((s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')){
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
	return 0;
}

