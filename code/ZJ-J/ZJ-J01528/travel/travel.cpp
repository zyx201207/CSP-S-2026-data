#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1])cout<<"1";else{cout<<"0000";return 0;}
	if(b[0]==d[0]&&b[1]==d[1])cout<<"1";else cout<<"0";
	if(b[0]==d[0]&&b[1]==d[1]){
		if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){cout<<"11";return 0;}
		else if(b[2]!='D'&&d[2]!='F'&&b[2]!='F'&&d[2]!='D')cout<<"1";
		else cout<<"0";
	}else cout<<"0";
	int na=b[2]-'A'+1,nb=d[2]-'A'+1;
	bool f=b[2]=='C'&&d[2]=='D'?1:0;
	if(b[0]==d[0]&&b[1]==d[1]&&abs(na-nb)==1&&!f)cout<<"1";
	else cout<<"0";
	return 0;
}
