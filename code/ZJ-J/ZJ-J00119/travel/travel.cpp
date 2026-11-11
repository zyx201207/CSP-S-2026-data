#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			char a=s1[2],b=s2[2];
			if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='C'&&b=='B'||a=='B'&&b=='C'||a=='A'&&b=='C'||a=='C'&&b=='A'||a=='D'&&b=='F'||a=='F'&&b=='D'){
				cout<<"1";
				ll x=int(a),y=int(b);
				if(a+1==b||b+1==a)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
}
