#include<bits/stdc++.h>
using namespace std;
string c,s,tc,ts;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>tc>>ts;
	if(c==tc){
		cout<<"1";
		if(s[1]==ts[1]&&s[0]==ts[0]){
			cout<<"1";
			if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(ts[2]=='A'||ts[2]=='B'||ts[2]=='C')||(s[2]=='D'||s[2]=='e')&&(ts[2]=='D'||ts[2]=='e')){
				cout<<"1";
				if(s[2]==ts[2]+1||ts[2]==s[2]+1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
}
