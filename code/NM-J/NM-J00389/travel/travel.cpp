#include<bits/stdc++.h>
using namespace std;
string c,t,a,b,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>t>>a>>b;
	if(c==a){
        cout<<"1";
	}else{
        cout<<"0000";
        return 0;
	}
	if(t[1]==b[1]&&t[0]==b[0]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((t[2]=='D'&&b[2]=='C')||t[2]=='C'&&b[2]=='D'){
		cout<<"00";
		return 0;
	}else if(((t[2]>='A'&&t[2]<='C')&&(b[2]>='A'&&b[2]<='C'))||((t[2]=='D'&&b[2]=='F')&&(t[2]=='F'&&b[2]=='D'))){
		cout<<"1";
	}
	if(t[2]==(b[2]-'A'+1)%26+'A'){
		cout<<"1";
	}else if(b[2]==(t[2]-'A'+1)%26+'A'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
