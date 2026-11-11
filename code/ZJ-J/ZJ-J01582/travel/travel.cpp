#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="0000";
bool check1(string a,string b){
	if(c1==c2&&a[0]==b[0]&&a[1]==b[1]){
		if(a[2]=='A'&&b[2]=='B'||a[2]=='A'&&b[2]=='C'||a[2]=='B'&&b[2]=='C'||a[2]=='C'&&b[2]=='B'||a[2]=='B'&&b[2]=='A'||a[2]=='C'&&b[2]=='A')
			return 1;
		else if(a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D')
			return 1;
	}else return 0;
}bool check2(string a,string b){
	if(c1==c2&&a[0]==b[0]&&a[1]==b[1]){
		if(a[2]=='A'&&b[2]=='B'||a[2]=='B'&&b[2]=='C'||a[2]=='C'&&b[2]=='B'||a[2]=='B'&&b[2]=='A')
			return 1;
		else if(a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D')
			return 1;
	}else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans[0]='1';
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])ans[1]='1';
	if(check1(s1,s2)==1)ans[2]='1';
	if(check2(s1,s2)==1)ans[3]='1';
	cout<<ans;
	return 0;
}