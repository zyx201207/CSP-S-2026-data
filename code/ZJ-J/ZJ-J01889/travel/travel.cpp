#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int check(char x,char y){
	if('A'<=x&&'C'>=x){
		if('A'<=y&&'C'>=y)return 1;
		else return 0;
	}
	if('D'<=x&&'E'>=x){
		if('D'<=y&&'E'>=y)return 1;
		else return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1[2],s2[2]))cout<<1;
	else cout<<0;
	if(c1==c2&&abs(int(s1[2]-s2[2]))==1&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1[2],s2[2]))cout<<1;
	else cout<<0;
	return 0;
}
