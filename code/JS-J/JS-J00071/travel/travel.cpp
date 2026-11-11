#include<bits/stdc++.h>
using namespace std;
string c,cc,s,ss;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>cc>>s>>ss;
	if(c[0]==s[0]&&c[1]==s[1])cout<<1;
	else{
		cout<<"0000";return 0;
	}
	if(cc[0]==ss[0]&&cc[1]==ss[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((cc[2]=='A'||cc[2]=='B'||cc[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'))||((cc[2]=='D'||cc[2]=='F')&&(ss[2]=='D'||ss[2]=='F')))
	{
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(cc[2]=='D'||cc[2]=='F'){
		cout<<1;
		return 0;
	}
	else{
		if(abs(cc[2]-ss[2])==1){
			cout<<1;
			return 0;
		}
		else cout<<0;
	}
	return 0;
}
