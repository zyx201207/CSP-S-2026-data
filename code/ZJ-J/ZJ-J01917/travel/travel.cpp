#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>n>>c>>m;
	if(a!=c)cout<<"0000";
	else{
		b=(n[0]-'0')*10+n[1];
		d=(m[0]-'0')*10+m[1];
		if(b!=d)cout<<"1000";
		else{
			if((n[2]=='D'&&m[2]=='F')||(n[2]=='F'&&m[2]=='D')||(n[2]=='A'&&m[2]=='B')||(n[2]=='B'&&m[2]=='A')||(n[2]=='B'&&m[2]=='C')||(n[2]=='C'&&m[2]=='B')||(n[2]=='A'&&m[2]=='C')||(n[2]=='C'&&m[2]=='A')){
				if((n[2]=='D'&&m[2]=='F')||(n[2]=='F'&&m[2]=='D')||(n[2]=='A'&&m[2]=='B')||(n[2]=='B'&&m[2]=='A')||(n[2]=='B'&&m[2]=='C')||(n[2]=='C'&&m[2]=='B'))cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
	}
	return 0;
}
