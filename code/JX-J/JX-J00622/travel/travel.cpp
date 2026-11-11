#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	char a='0',b='0',c='0',d='0';
	if(s1==s2){
		a='1';
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
				b='1';
				if((c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C')){
					c='1';
					if(abs(int(c1[2]-c2[2]))==1){
						d='1';
					}
				}
				if((c1[2]=='D'&&c2[2]=='F')||(c1[2]=='F'&&c2[2]=='D')){
					c='1';
					d='1';
				}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
