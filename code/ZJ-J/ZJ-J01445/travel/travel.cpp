#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,ss,ss1;cin>>s>>ss;
	string sm1=ss.substr(0,2);
	cin>>s1>>ss1;
	string sm2=ss1.substr(0,2);
	if(s==s1){
		cout<<1;
		if(sm1==sm2){
			cout<<1;
			if((ss[2]<='C'&&ss1[2]<='C')||(ss[2]>'C'&&ss1[2]>'C')){
				cout<<1;
				if(abs(ss[2]-ss1[2])==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	else cout<<"0000";
}