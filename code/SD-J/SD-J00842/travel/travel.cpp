#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string ans="00000";
	if(c1==c2) ans[0]='1';
	string num1,num2;
	num1+=s1[0];num1+=s1[1];
	num2+=s2[0];num2+=s2[1];
	if(ans[0]=='1'&&num1==num2)
		ans[1]='1';
	if(ans[0]=='1'&&ans[1]=='1'&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')))
		ans[2]='1';
	if(ans[0]=='1'&&ans[1]=='1'&&ans[2]=='1'&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')))
		ans[3]='1';
	for(int i=0;i<4;i++)
		cout<<ans[i];
	return 0;
}
