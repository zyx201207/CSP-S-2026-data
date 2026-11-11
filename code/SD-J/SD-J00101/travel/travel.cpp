#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else{
		cout<<"0";
		f=1;
	}
	if(f==0&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<"1";
	else{
		cout<<"0";
		f=1;
	}
	if(f==0&&((s1[2]>'C'&&s2[2]>'C')||(s1[2]<='C'&&s2[2]<='C')))cout<<"1";
	else{
		cout<<"0";
		f=1;
	}
	if(f==0&&abs(s1[2]-s2[2])==1)cout<<"1";
	else{
		cout<<"0";
		f=1;
	}
	return 0;
} 
