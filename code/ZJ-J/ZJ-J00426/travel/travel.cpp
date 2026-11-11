#include<bits/stdc++.h>
using namespace std;
string a,b,s1,s2;
int flag1=0,flag2=0,flag3=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		flag1=1;
		cout<<1;
	}
	else cout<<0;
	if(flag1&&s1[0]+s1[1]==s2[0]+s2[1]){
		flag2=1;
		cout<<1;
	}
	else cout<<0;
	if(flag1&&flag2&&s1[2]<'D'&&s2[2]<'D'||s1[2]>'C'&&s2[2]>'C'){
		flag3=1;
		cout<<1;
	}
	else cout<<0;
	cout<<(flag1&&flag2&&flag3&&(abs(s1[2]-s2[2])==1||min(s1[2],s2[2])=='D'&&max(s1[2],s2[2])=='F'));
	return 0;
}
