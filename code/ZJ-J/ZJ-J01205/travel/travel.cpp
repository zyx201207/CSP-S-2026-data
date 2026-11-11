#include <bits/stdc++.h>
#define ll long long
using namespace std;

string a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	ll aa,bb;
	aa=b[0]-'0';
	aa*=10;
	aa+=b[1]-'0';
	bb=(d[0]-'0')*10+d[1]-'0';
	if(a==c&&aa==bb&&(b[2]+1==d[2]||b[2]-1==d[2])&&!((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C'))){
		cout<<"1111";
	}
	else if(a==c&&aa==bb&&((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))){
		cout<<"1110";
	}
	else if(a==c&&aa==bb){
		cout<<"1100";
	}
	else if(a==c){
		cout<<"1000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
