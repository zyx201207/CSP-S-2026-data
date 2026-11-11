#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]&&c1[0]==c2[0]){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1) cout<<"1";
				else cout<<"0";
			}
			else if('D'==s1[2]||s1[2]=='F'&&'D'==s2[2]||s2[2]=='F'){
				cout<<"1";
				if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}