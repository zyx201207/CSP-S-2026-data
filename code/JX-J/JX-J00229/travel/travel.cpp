#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])cout<<1;
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else cout<<0;
	if(((s1[2]-'A')%5<3 && (s2[2]-'A')%5<3)  ||  ((s1[2]-'A')%5>2 && (s2[2]-'A')%5>2)){
		cout<<1;
		if((s1[2]-'A')%5-(s2[2]-'A')%5==1||(s1[2]-'A')%5-(s2[2]-'A')%5==-1)cout<<1;
		else cout<<0;
	}
	else cout<<"00";
	if((s1[2]-'A')%5)
	return 0;
}
