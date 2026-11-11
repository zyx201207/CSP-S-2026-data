#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	string <c1,s1,c2,s2>;
	int b,z,h,k;
	cin>>c1>>s1>>c2>>s2;
	if(c1=c2){
		b="1";
	}
	else{
		b="0";
	}
	if(s1[0]==s2[0] and s1[1]==s2[1]){
		z="1";
	}
	else{
		z="0";
	}
	if(s1[2]="A" or "B" or "C" and s2[2]=A" or "B" or "C"){
		h="1";
	}
	else{
		h="0";
	}
	if(s1[0]==s2[0] and s1[1]==s2[1] and s1[2]!=s2[2] and s1[2]="A" and s2(2)="B" or s1[2]="B" and s2(2)="A" or "c" or s1[2]="c" and s2(2)="B" or s1[2]="E" and s2(2)="F" or s1[2]="F" and s2(2)="E"   ){
		k="1";
	}
	else{
		k="0";
	}
	cout<<b<<z<<h<<k;
	return 0;
}