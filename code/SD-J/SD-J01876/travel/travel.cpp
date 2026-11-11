#include<bits/stdc++.h>
using namespace std;
char s1[20];
string x1,c1,x2,c2;
int f1=0,f2=0,f3=0,f4=0,t=0,t1=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin.getline(s1,20);
	x1+=s1[0];
	x1+=s1[1];
	c1+=s1[3];
	c1+=s1[4];
	c1+=s1[5];
	x2+=s1[7];
	x2+=s1[8];
	c2+=s1[10];
	c2+=s1[11];
	c2+=s1[12];
	if(x1==x2) f1=1;
	if(f1&&(c2[0]==c1[0]&&c2[1]==c1[1])) f2=1;
	if(f2&&((c1[2]>='A'&&c1[2]<='C')&&(c2[2]>='A'&&c2[2]<='C'))||((c1[2]>='D'&&c1[2]<='F')&&(c2[2]>='D'&&c2[2]<='F'))){
		f3=1;
		t=((c1[2]>='A'&&c1[2]<='C')&&(c2[2]>='A'&&c2[2]<='C'));
		t1=((c1[2]>='A'&&c1[2]<='C')&&(c2[2]>='A'&&c2[2]<='C'));
	}
	if(f3){
		if(t){
			if((c1[2]-'0')-1==c2[2]-'0'||(c1[2]-'0')+1==c2[2]-'0') f4=1; 
		}
		else if(t1){
			if((c1[2]-'0')-2==c2[2]-'0'||(c1[2]-'0')+2==c2[2]-'0') f4=1; 
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
