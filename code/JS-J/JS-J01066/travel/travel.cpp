#include<bits/stdc++.h>
using namespace std;
string ans="0000";
string s1,s2,c1,c2;
bool check(char x,char y){
	if(x>='A' and x<='C' and y>='A' and y<='C')return 1;
	else if((x=='D' or x=='F') and (y=='D' or y=='F'))return 1;
	return 0;
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
		string num1=s1.substr(0,2);
		string num2=s2.substr(0,2);
		 
		if(num1==num2){
			ans[1]='1';
			char id1=s1[2],id2=s2[2];
			if(check(id1,id2)){
				ans[2]='1';
				if(id1==char(id2+1) or id2==char(id1+1)){
					ans[3]='1';
				}
		}
	}
}
	cout<<ans;
	
	
	
	return 0;
}
