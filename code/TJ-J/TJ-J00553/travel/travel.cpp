#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char c1[4],c2[4],jc[4],j[4];
int ans1,ans2,ans3;
int tongpai(char x,char y,char z,char k){
	if(x==z&&y==k) return 1;
	return 0;
}
int tongce(char x,char y){
	int pp=0,yy=0;
	for(int i=1;i<=3;i++){
		if(x==jc[i]) pp=15;
		if(y==jc[i]) yy=15;
	}
	for(int i=1;i<=3;i++){
		if(x==j[i]) pp=1;
		if(y==j[i]) yy=1;
	}
	if(pp==yy) return 1;
	return 0;
}
int xianglin(char x,char y){
	if(x=='D'&&y=='F') return 1;
	if(y=='D'&&x=='F') return 1;
	int pp=x-'A',yy=y-'A';
	if(abs(pp-yy)==1) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	jc[1]='A',jc[2]='B',jc[3]='C';
	j[1]='D',j[2]='F';
	cin>>s1;
	cin>>c1[1]>>c1[2]>>c1[3];
	cin>>s2;
	cin>>c2[1]>>c2[2]>>c2[3];
	if(s1==s2) ans1=1;
	else{
		cout<<"0000";
		return 0;
	}
	if(tongpai(c1[1],c1[2],c2[1],c2[2])) ans2=1;
	else{
		cout<<"1000";
		return 0;
	}
	if(tongce(c1[3],c2[3])) ans3=1;
	else{
		cout<<"1100";
		return 0;
	}
	if(xianglin(c1[3],c2[3])){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
} 
