#include<bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0,d=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]<=67&&s2[2]<=67&&s1[2]>=65&&s2[2]>=65||s1[2]>=68&&s2[2]>=68&&s1[2]<=69&&s2[2]<=69){
				if(s1[2]-1==s2[2]||s1[2]+1==s2[2]){
					d=1;
				}
				c=1;
			}
			b=1;
		}
		a=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}