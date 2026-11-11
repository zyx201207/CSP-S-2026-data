#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char a=s1[2],b=s2[2];
	if(('A'<=b&&b<='C'&&'A'<=a&&a<='C')||('D'<=b&&b<='E'&&'D'<=a&&a<='E')) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if(abs(a-b)==1) cout<<1;
	else cout<<0;
	return 0;
}