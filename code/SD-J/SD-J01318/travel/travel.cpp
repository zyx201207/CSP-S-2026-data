#include <bits/stdc++.h>
#define int long long
using namespace std;
//const int N=;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
			if(abs(s1[2]-s2[2])==1||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
				cout<<"111\n";
			}
			else{
				cout<<"110\n";
//				cout<<abs(s1[2]-s2[2])<<"\n";
			}
		}
		else{
			cout<<"100\n";
		}
	}
	else{
		cout<<"000\n";
	}
	
	return 0;
}
