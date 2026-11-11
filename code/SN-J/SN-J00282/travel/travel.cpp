#include <bits/stdc++.h>
using namespace std;
string s;
int a,b1,b2,c,d1,d2,e1,e2;
bool check(){
	if(a!=c)return 0;
	if(abs(b1-d1)>1)return 0;
	if(abs(b1-d1)==1 && b2!=d2){
		return 0;
	}
	if(e1!=e2)return 0;
	if(e1==1 && e2==1 && abs(b2-d2)>1){
		return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s",s.c_str());
	a=stoi(s);
	scanf("%s",s.c_str());
	if(s[0]=='1'){
		b1+=10;
	}
	b1+=s[1]-'0';
	b2=s[2]-64;
	scanf("%s",s.c_str());
	c=stoi(s);
	scanf("%s",s.c_str());
	if(s[0]=='1'){
		d1+=10;
	}
	d1+=s[1]-'0';
	d2=s[2]-64;	
	if(b2>3)e1=2;
	else e1=1;
	if(d2>3)e2=2;
	else e2=1;
	if(a==c)printf("%d",1);
	else printf("%d",0);
	if(b1==d1 && a==c)printf("%d",1);
	else printf("%d",0);
	if(b1==d1 && a==c && e1==e2)printf("%d",1);
	else printf("%d",0);
	if(check() && e1==e2)printf("%d",1);
	else printf("%d",0);		
	return 0;
}
