#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
string a1,a2,b1,b2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		if((a2[0]-'0')*10+(a2[1]-'0')==(b2[0]-'0')*10+(b2[1]-'0')){
			cout<<1;
			if(a2[2]=='D'&&b2[2]=='F'||a2[2]=='F'&b2[2]=='D'||a2[2]=='A'&&b2[2]=='B'||a2[2]=='A'&&b2[2]=='C'||a2[2]=='B'&&b2[2]=='C'||a2[2]=='B'&&b2[2]=='A'||a2[2]=='C'&&b2[2]=='A'||a2[2]=='C'&&b2[2]=='B'){
				cout<<1;
				if(a2[2]=='A'&&b2[2]=='C'||a2[2]=='C'&&b2[2]=='A'){
					cout<<"0";
				}else cout<<1;
			}else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

