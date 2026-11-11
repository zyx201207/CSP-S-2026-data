#include <bits/stdc++.h>
using namespace std;
string c,C,s,S;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>s>>C>>S;
//	cout<<c<<endl<<s<<endl<<C<<endl<<S<<endl;
	if(c==C){
		cout<<1;
		if(s[0]==S[0] && s[1]==S[1]){
			cout<<1;
			if(s[2]>='D' && S[2]>='D' || s[2]<='C' && S[2]<='C'){
				cout<<1;
				if(s[2]>='D' && S[2]>='D' || (s[2]=='B' || S[2]=='B')){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	
	
	return 0;
}