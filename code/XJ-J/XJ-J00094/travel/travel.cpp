#include<bits/stdc++.h>
using namespace std;
int travel1(char c1,char s1,char c2,char s2){
	if(c1==c2)return 1;
	else{
		return 0;
	}
}
int travel2(int c1,char s1,int c2,char s2){
	if(c1==c2)return 1;
	else{
		return 0;
	}
	
	int s1c[2];
	int s2c[2];
	for(int i=0;i<2;i++){
	}
}
int travel3(int c1,char s1,int c2,char s2){
	if(c1==c2)return 1;
	else{
		return 0;
	}
}
int travel4(int c1,char s1,int c2,char s2){
	if(c1==c2)return 1;
	else{
		return 0;
	}
	return int(s1);
	if(s1-1==s2||s1+1==s2)return 1;
	else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char b,d,a,c;
	cin >> a >> b >> c >> d;
	cout << travel1(a,b,c,d) << travel2(a,b,c,d) << travel3(a,b,c,d) <<travel4(a,b,c,d);
	return 0;
}
