#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int sum1,sum2;
bool flag1,flag2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	sum1=10*(s1[0]-'0')+(s1[1]-'0');
	sum2=10*(s2[0]-'0')+(s2[1]-'0');
	if(sum1==sum2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='D'||s1[2]=='F') flag1=1;
	if(s2[2]=='D'||s2[2]=='F') flag2=1;
	if(flag1==flag2) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='C'){
		cout<<"0";
		return 0;
	}
	if(s1[2]=='C'&&s2[2]=='A'){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
