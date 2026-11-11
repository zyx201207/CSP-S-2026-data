#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2,s1tint,s2tint,if1,if2,if3;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x = (char)s1[2];
	y = (char)s2[2];
	if(c1==c2){cout<<1;if1=1;}else{cout<<0;}
	if(s1[0]=='0'){s1tint=s1[1]-'0';}else{s1tint=(s1[0]-'0')*10+(s1[1]-'0');}
	if(s2[0]=='0'){s2tint=s2[1]-'0';}else{s2tint=(s1[0]-'0')*10+(s2[1]-'0');}
	if(if1==1&&s1tint==s2tint){cout<<1;if2=1;}else{cout<<0;}
	if((if1==1&&if2==1)&&(x=='A'&&y=='B')||(x=='A'&&y=='C')||(x=='B'&&y=='C')||(x=='B'&&y=='A')||(x=='C'&&y=='A')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D')&&(if2==1)){if(if2==0||if1==0){cout<<0;}else{cout<<1;if3=1;}}else{cout<<0;}
	if((if1==1&&if2==1&&if3==1)&&((((int)x)+1==y)||(((int)y+1)==x))){cout<<1;}else{cout<<0;}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
