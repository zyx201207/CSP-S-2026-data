#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	char c1[3],s1[4],c2[3],s2[4];
	char a1='0',a2='0',a3='0';
	int a=0,b=0,c=0,d=0;
	scanf("%s",c1);
	scanf("%s",s1);
	scanf("%s",c2);
	scanf("%s",s2);
	if (s1[2]>='A'&&s1[2]<='C') a1='1';
	if (s1[2]>='D'&&s1[2]<='F') a1='2';
	if (s2[2]>='A'&&s2[2]<='C') a2='1';
	if (s2[2]>='D'&&s2[2]<='F') a2='2';
	if(s2[2]-s1[2]==1&&a1==a2) a3='1';
	if(s1[2]-s2[2]==1&&a1==a2) a3='1';
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) a3='1';
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		a=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			b=1;
			if(a1==a2){
				c=1;
				if(a3=='1') d=1;
			}
		}
	}
	printf("%d%d%d%d",a,b,c,d);
	

	//02 01A 02 01B
	return 0;
} 
