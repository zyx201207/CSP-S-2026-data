#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1;
	string c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		a=1;
		if((c2[0]-'0')*10+(c2[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')){
			b=1;
			if((c2[2]<='C'&&s2[2]<='C')||(c2[2]>='D'&&s2[2]>='D')){
				c=1;
				if(abs(c2[2]-s2[2])==1){
					d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
} 
