#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int s=0,a=0,b=0,c=0;
	cin>>c1>>s1>>c2>>s2;
	char e1=s1[2],e2=s2[2];
	if(c1!=c2){
		cout<<"0000";
	}
	if(c1==c2){
		s=1;
		if(s1[0]==s2[0]){
			a=1;
			if(s1[1]==s2[1]){
				b=1;
				if(s2[2]-s1[2]==1){
					c=1;
				}else if(s1[2]-s2[2]==1){
					c=1;
				}else {
					c=0;}
			}else {
				b=0;}
		}else {a=0;}
	}
	if(int(e1)==68 && int(e2)==67){c=0;b=0;}
	if(int(e1)==67 && int(e2)==68){c=0;b=0;	}	
		cout<<s<<a<<b<<c;
	return 0;
}
