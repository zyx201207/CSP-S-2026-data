#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a=0,b=0,c=0,d=1;
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)a=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1])b=1;
	int x,y;
	if((s1[2]=='D')&&(s1[2]=='F'))x=1;
	else x=0;
	if(s2[2]=='D'&&s2[2]=='F')y=1;
	else y=0;
	if(x==y)c=1;
	if(b==1&&c==1){
		if(s1[2]=='A'&&s2[2]=='C')d=0;
		else if(s1[2]=='C'&&s2[2]=='A')d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
