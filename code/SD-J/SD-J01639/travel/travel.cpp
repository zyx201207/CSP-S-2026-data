#include<bits/stdc++.h>
#define st string
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	st s1,s2;
	st a;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a+="1";
		if((s1[0]==s2[0])&&(s1[1]==s2[1]))
		{
			a+="1";
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
				a+="1";
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')){
					a+="1";
				}
				else{
					a+="0";
				}
			}
			else{
				a+="0";
			}
		}
		else{
			a+="0";
		}
		}
	else{
		a+="0";
	}
	cout<<a;
	return 0;
}
