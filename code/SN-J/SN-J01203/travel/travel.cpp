#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
bool f1,f2,f3,f4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)f1=1;
	if(f1==1 && s1[0]==s2[0] && s1[1]==s2[1])f2=1;
	if(f2==1){
		if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
			f3=1;f4=1;
		}
		if(s1[2]=='A'&&s2[2]=='B'){
			f3=1;f4=1;
		}
		if(s1[2]=='A'&&s2[2]=='C')f3=1;
		if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
			f3=1;f4=1;
		}
		if(s1[2]=='C'&&s2[2]=='A')f3=1;
		if(s1[2]=='C'&&s2[2]=='B'){
			f3=1;f4=1;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
