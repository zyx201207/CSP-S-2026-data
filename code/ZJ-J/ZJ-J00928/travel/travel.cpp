#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool a=0,b=0,c=0,d=0;
	if(c1==c2){
		a=1;
		if(a){
			if(s1.substr(0,2)==s2.substr(0,2)){
				b=1;
				if(b){
					if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'){
						c=1;
						if(c){
							if(abs(s1[2]-s2[2])==1&&(s1[2]!='C'&&s2[2]!='D')) d=1;
						}
					}
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}