#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1;
string c2,s2;
int num(char op){
	if(op<='C')return 1;
	else return -1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2))cout<<1;
	else cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&num(s1[2])==num(s2[2])){
		cout<<1;
	}else cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&num(s1[2])==num(s2[2])&&abs(int(s1[2]-s2[2]))==1)cout<<1;
	else cout<<0;
	return 0;
}