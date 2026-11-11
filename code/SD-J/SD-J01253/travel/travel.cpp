#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			cout<<1;
			if(s2[2]=='D'&&c2[2]=='F'||s2[2]=='F'&&c2[2]=='D'){
				cout<<11;
			}else if(s2[2]=='A'&&c2[2]=='B'||s2[2]=='B'&&c2[2]=='A'||s2[2]=='B'&&c2[2]=='C'||s2[2]=='C'&&c2[2]=='B'){
				cout<<11;
			}else if(s2[2]=='A'&&c2[2]=='C'||s2[2]=='C'&&c2[2]=='A'){
				cout<<10;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

