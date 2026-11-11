#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string ans="";
	if(a==c){
		ans=ans+"1";
		if(b[0]+b[1]==d[0]+d[1]){
			ans=ans+"1";
			if(((b[2]-'0'>='A'-'0' && b[2]-'0'<='C'-'0')&&(d[2]-'0'>='A'-'0' && d[2]-'0'<='C'-'0')) ||  ((b[2]=='D' && d[2]=='F') || (b[2]=='F' && d[2]=='D'))){
				ans=ans+"1";
				if(abs((b[2]-'0')-(d[2]-'0'))==1){
					ans=ans+"1";
				}else{
					ans=ans+"0";
				}
			}else{
				ans=ans+"00";
			}
		}else{
			ans=ans+"000";
		}
	}else{
		ans=ans+"0000";
	}
	cout<<ans;
	return 0;
}
