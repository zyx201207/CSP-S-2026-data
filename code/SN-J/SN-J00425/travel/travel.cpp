#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if((c1==c2)&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'))){
		cout<<1;
	}else{
		cout<<0;
	}
	int cs1=(int)s1[2];
	int cs2=(int)s2[2];
	int cnt=abs(cs1-cs2);
//	cout<<cnt;
	if((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&(cnt==1)&&(s1[2]!='C'&&s2[2]!='D')&&(s1[2]!='D'&&s2[2]!='C')){
		cout<<1;
	}
	else if((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
