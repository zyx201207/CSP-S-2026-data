#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
string ans="";
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans+="1";
		if(b[0]==d[0]&&b[1]==d[1]){
			ans+="1";
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')){
				ans+="1";
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='E'&&d[2]=='F')||(b[2]=='F'&&d[2]=='E')){
					ans+="1";
				}else ans+="0";
			}
			else ans+="00";
		}else ans+="000";
	}
	else ans+="0000";
	cout<<ans;
	return 0;
}
