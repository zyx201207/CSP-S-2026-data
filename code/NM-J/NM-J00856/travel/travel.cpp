#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a="0000",b="1000",c="1100",d="1110",e="1111";

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){cout<<a;};
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))||((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))){
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
				cout<<e;}
				else cout<<d;
			}else cout<<c;
		}else cout<<b;
	};
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
