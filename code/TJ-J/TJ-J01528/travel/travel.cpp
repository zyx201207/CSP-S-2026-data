#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned __int128 _i;
const int N=1e9;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	string a1=s1.substr(0,2);
	string a2=s2.substr(0,2);
	if(a1==a2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	string b1=s1.substr(2,1);
	string b2=s2.substr(2,1);
	if(((b1[0]<='F'&&b1[0]>='D')&&(b2[0]<='F'&&b2[0]>='D'))||((b1[0]<='C'&&b1[0]>='A')&&(b2[0]<='C'&&b2[0]>='A'))){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(((b1[0]=='D'&&b2[0]=='F')||(b1[0]=='F'&&b2[0]=='D'))||((b1[0]=='A'&&b2[0]=='B')||(b1[0]=='B'&&b2[0]=='A')||(b1[0]=='B'&&b2[0]=='C')||(b1[0]=='C'&&b2[0]=='B'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
