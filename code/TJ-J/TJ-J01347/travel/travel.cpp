#include<bits/stdc++.h>
using namespace std;
int x,p,c,z;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int m=c1[1]-48+(c1[0]-48)*10,n=c2[1]-48+(c2[0]-48)*10;
	if(m!=1 && m!=16 && n!=1 && n!=16){
		if(c1==c2){
			x=1;
			if(s1[0]+s1[1]==s2[0]+s2[1]){
				p=1;
				if(s1[2]<='C' && s2[2]<='C'){
					c=1;
					if(abs(s1[2]-s2[2])==1){
						z=1;
					}
				}else if(s1[2]>='D' && s2[2]>='D'){
					c=1;
					z=1;
				}
			}
		}
	}
	cout<<x<<p<<c<<z;
	return 0;
} 
