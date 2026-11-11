//t 2026-10-31 8:15
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
bool flag1=1,flag2=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c2.size();i++){
		if(c1[i]!=c2[i]) flag1=0;
	}
	if(flag1) cout<<1;
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(((s1[2]>'C'&&s2[2]>'C')||(s1[2]<='C'&&s2[2]<='C'))&&s1[0]==s2[0]&&s1[1]==s2[1]&&flag1){
		cout<<1;
	}else{
		cout<<0;
		flag2=0;
	}
	bool flag3=0;
	if(s2[2]>='D'&&s1[2]>='D'){
		if(s2[2]=='D'&&s1[2]=='F') flag3=1;
		if(s2[2]=='F'&&s1[2]=='D') flag3=1;
	}else{
		if(s2[2]=='A'&&s1[2]=='B') flag3=1;
		if(s2[2]=='B'&&s1[2]=='A') flag3=1;
		if(s2[2]=='B'&&s1[2]=='C') flag3=1;
		if(s2[2]=='C'&&s1[2]=='B') flag3=1;
	}
	if(flag2&&flag3) cout<<1;
	else cout<<0;
	return 0;
}
