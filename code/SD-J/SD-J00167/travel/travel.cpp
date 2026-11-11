#include<bits/stdc++.h>
using namespace std;
struct node{
	int c,cc;
	int s,s1;
	char s2;
};
node r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	char rr,rrr,rrrr,rrrrr,rrrrrr,xx,xxx,xxxx,xxxxx,xxxxxx;
	cin>>rr>>rrr>>rrrr>>rrrrr>>rrrrrr>>xx>>xxx>>xxxx>>xxxxx>>xxxxxx;
	r.c=(int)(rr);
	r.cc=(int)(rrr);
	r.s=(int)(rrrr);
	r.s1=(int)(rrrrr);
	r.s2=rrrrrr;
	x.c=(int)(xx);
	x.cc=(int)(xxx);
	x.s=(int)(xxxx);
	x.s1=(int)(xxxxx);
	x.s2=xxxxxx;
	
	bool f=0;
	
	if((r.c==x.c)&&(r.cc==x.cc)) cout<<1;
	else {cout<<0;f=1;}
		
	if(f==0&&((r.s==x.s)&&(r.s1==x.s1))) cout<<1;
	else {cout<<0;f=1;}
	
	if(f==0&&((r.s2>='D'&&x.s2>='D')||(r.s2<='C'&&x.s2<='C'))) cout<<1;
	else {cout<<0;f=1;}
				
	if(f==0&&(r.s2>='D'&&x.s2>='D')) cout<<1;
	else if(f==0&&((r.s2=='A'&&x.s2=='B')||(x.s2=='A'&&r.s2=='B')||(r.s2=='B'&&x.s2=='C')||(x.s2=='B'&&r.s2=='C'))) cout<<1;			
	else {cout<<0;f=1;}

	return 0;
}

