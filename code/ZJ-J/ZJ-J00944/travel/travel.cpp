#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,t,s1,t1;
	cin>>s>>t>>s1>>t1;
	if(s==s1){
		cout<<1;
		if(t[0]==t1[0] && t[1]==t1[1]){
			cout<<1;
			char a=(char)max((int)t[2],(int)t1[2]),b=(char)min((int)t[2],(int)t1[2]);
			if(a=='F' && b=='D'){
				cout<<11;
			}
			else if(a=='B'&&b=='A'||a=='C'&&b=='B'){
				cout<<11;
			}
			else if(a=='C'&&b=='A'){
				cout<<10;
			}
			else{
				cout<<00;
			}
		}
		else{
			cout<<000;
		}
	}
	else{
		cout<<0000;
	}
	return 0;
}