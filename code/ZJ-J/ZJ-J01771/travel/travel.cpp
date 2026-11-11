#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool check(){
	char op1=s1[s1.size()-1],op2=s2[s2.size()-1];
	if(op1<='C'&&op2<='C')return 1;
	if(op1>'C'&&op2>'C')return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			if(check()){
				cout<<1;
				if(abs(s1[s1.size()-1]-s2[s2.size()-1])==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
