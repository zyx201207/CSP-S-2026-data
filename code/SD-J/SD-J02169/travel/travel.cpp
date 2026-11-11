#include<bits/stdc++.h>
using namespace std;
string s[5];
char c[5][10],c1,c2;
int a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
 	for(int i=1;i<=4;i++){
 		cin>>s[i];
	}
	if(s[1][0]==s[3][0]&&s[1][1]==s[3][1])a1=1;
	if(a1&&s[2][0]==s[4][0]&&s[2][1]==s[4][1])a2=1;
	if(a2&&((s[2][2]=='D'&&s[2][2]<='F'&&s[4][2]>='D'&&s[4][2]<='F')||(s[2][2]>='A'&&s[2][2]<='C'&&s[4][2]>='A'&&s[4][2]<='C')))a3=1;
	if(a3&&(abs((int)s[2][2]-s[4][2]))==1)a4=1;
	printf("%d%d%d%d",a1,a2,a3,a4);
	return 0;
	
}
