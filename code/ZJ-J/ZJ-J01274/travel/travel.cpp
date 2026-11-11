#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
string ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)ans[1]='1';
	else ans[1]='0';
	if(s2[1]==s4[1]&&ans[1]=='1')ans[2]='1';
	else ans[2]='0';
	if(ans[2]=='1'&&ans[1]=='1'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')ans[3]='1';
			else ans[3]='0';
		}
		if(s2[2]=='D'||s2[2]=='E'){
			if(s4[2]=='D'||s4[2]=='E')ans[3]='1';
			else ans[3]='0';
		}
	}
	else ans[3]='0';
	int pos1=s2[1]-'0',pos2=s4[1]-'0';
	int num1=s2[2]-'A'+1,num2=s4[2]-'A'+1;
	if(pos1!=pos2&&abs(pos1-pos2)<=1&&ans[1]=='1'){
		if(num1==num2)ans[4]='1';
		else ans[4]='0';
	}
	else if(pos1==pos2&&ans[1]=='1'){
		if(abs(num1-num2)<=1&&!((num1==3&&num2==4)||(num1==4&&num2==3)))ans[4]='1';
		else ans[4]='0';
	}
	else ans[4]='0';
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}
