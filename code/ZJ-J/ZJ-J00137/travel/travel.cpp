#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		printf("0000\n");
		return 0;
	}
	printf("1");
	for(int i=0;i<2;i++){
		int t=s1[i]-'0';
		n=n*10+t;
	}
	for(int i=0;i<2;i++){
		int t=s2[i]-'0';
		m=m*10+t;
	}
	if(n!=m){
		printf("000\n");
		return 0;
	}
	printf("1");
	if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='E' && s2[2]>='D' && s2[2]<='E')){
		printf("1");
		if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='E') || (s2[2]=='A' && s1[2]=='B') || (s2[2]=='B' && s1[2]=='C') || (s2[2]=='D' && s1[2]=='E')) printf("1\n");
		else printf("0\n");
	}else printf("00\n");
	return 0;
}
