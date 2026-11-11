#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1=0,a2=0,a3=0,a4=0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string h1=to_string(s1[0]+s1[1]),h2=to_string(s2[0]+s2[1]);
	if(h1==h2){
		a2=1;
	}
	int a,b;
	if('A'<=s1[2]&&'C'>=s1[2]){
		a=1;
	}
	else{
		a=2;
	}
	if('A'<=s2[2]&&'C'>=s2[2]){
		b=1;
	}
	else{
		b=2;
	}
	if(a==b&&a2){
		a3=1;
	}
	if(c1==c2){
		a1=1;
	}
	else{
		a2=0;
		a3=0;
	}
	if(a1&&a2&&a3&&abs(s1[2]-s2[2])==1){
		a4=1;
	}
	cout<<a1<<a2<<a3<<a4<<"\n";
	return 0;
}
