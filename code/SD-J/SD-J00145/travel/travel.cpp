#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if((s1[0]!=s2[0])||(s1[1]!=s2[1])){
		cout<<"000";
		return 0;
	}
	cout<<1;
	char a=s1[2],b=s2[2];
	if('A'<=a&&a<='C'&&'A'<=b&&b<='C'){
		if(abs(a-b)==1)cout<<11;
		else cout<<"10";
	}
	else if('D'<=a&&a<='E'&&'D'<=b&&b<='E')cout<<11;
	else cout<<"00";
	return 0;
}
