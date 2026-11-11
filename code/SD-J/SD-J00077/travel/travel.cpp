#include<bits/stdc++.h>
using namespace std;
int c[5]={1,1,1,2,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F')s1[2]='E';
	if(s2[2]=='F')s2[2]='E';
	if(c1!=c2){
		puts("0000");
		return 0;
	}
	int p1=s1[0]*10+s1[1],p2=s2[0]*10+s2[1];
	if(p1!=p2){
		puts("1000");
		return 0;
	}
	int l1=s1[2]-'A',l2=s2[2]-'A';
	if(c[l1]!=c[l2]){
		puts("1100");
		return 0;
	}
	if(abs(l1-l2)!=1){
		puts("1110");
		return 0;
	}
	puts("1111");
	return 0;
}
