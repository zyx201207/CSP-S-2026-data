#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((s1[2]=='A'||'B')&&(s2[2]=='A'||'B')||(s1[2]=='D'||'E'||'C')&&(s2[2]=='D'||'E'||'C')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(-2<s1[2]-s2[2]<2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
