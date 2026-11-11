#include<bits/stdc++.h>
using namespace std;
string c[5],s[5];
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2]){
		cout<<'1';
		if(s[1][0]==s[2][0]&&s[1][1]==s[2][1]){
			cout<<'1';
			if((s[1][2]<='C'&&s[2][2]<='C')||(s[1][2]>='D'&&s[2][2]>='D')){
				cout<<'1';
				if(!((s[1][2]=='A'&&s[2][2]=='C')||(s[1][2]=='C'&&s[2][2]=='A'))){
					cout<<'1';
				}
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
