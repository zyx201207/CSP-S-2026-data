#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c3;
	string s2,s4;
	cin>>c1>>s2>>c3>>s4;
	if(c1!=c3)cout<<"0000";
	else{
		cout<<'1';
		if((s2[0]-'0')*10+(s2[1]-'0')!=(s4[0]-'0')*10+(s4[1]-'0'))cout<<"000";
		else{
			cout<<'1';
			if((s2[2]>='A' && s2[2]<='C') && (s4[2]>='A' && s4[2]<='C')){
				cout<<'1';
				if((s2[2]=='A' && s4[2]=='B') || (s4[2]=='A' && s2[2]=='B') || (s2[2]=='B' && s4[2]=='C') || (s4[2]=='B' && s2[2]=='C'))cout<<'1';
				else cout<<'0';
			}
			else if((s2[2]=='D' && s4[2]=='F') || (s4[2]=='D' && s2[2]=='F')){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
	}
	return 0;
} 
