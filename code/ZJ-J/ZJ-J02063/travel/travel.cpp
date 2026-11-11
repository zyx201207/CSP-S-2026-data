#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2;
string s1,s2;
char a,b;
int hang1,hang2;
int get(string s){
	return (s[0]-'0')*10+s[1];
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	a=s1[2],b=s2[2];
	hang1=get(s1),hang2=get(s2);
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(hang1==hang2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(abs(a-b)>2||(a=='C'&&b=='D')||(a=='D'&&b=='C')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(a-b)==1) cout<<1;
	else cout<<0;
}
//100