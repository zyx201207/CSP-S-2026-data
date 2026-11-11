#include<bits/stdc++.h>
using namespace std;
int x,y,a,b,f1,f2;
char s1[5],s2[5];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s1>>y>>s2;
	if(x!=y){
		cout<<"0000";
		return 0;
	}
	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	if(a!=b){
		cout<<"1000";
		return 0;
	}
	if('A'<=s1[2]&&s1[2]<='C')f1=1;
	if('A'<=s2[2]&&s2[2]<='C')f2=1;
	if(f1!=f2){
		cout<<"1100";
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='C'||
	s1[2]=='C'&&s2[2]=='A'){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}