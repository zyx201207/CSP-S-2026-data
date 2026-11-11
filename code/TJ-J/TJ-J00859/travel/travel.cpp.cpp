#include <bits/stdc++.h>
using namespace std;
char s1[20],s2[20];
int main() {
	int  c1,c2;
	int t1,t2,i,j,n,m,s3,s4,p=0,q=0,w=0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(i=1;i<=3;i++)
		cin>>s1[i];
	n=(s1[1]-48)*10;
	m=s1[2]-48;
	s3=s1[3]-64;
	t1=n+m;
	cin>>c2;
	for(i=1;i<=3;i++)
		cin>>s2[i];
 	n=(s2[1]-48)*10;
	m=s2[2]-48;
	s4=s2[3]-64;
	t2=n+m;
	if(c1==c2) cout<<1<<" ";
	else 
	{
		cout<<0<<" ";
		q=1;
	}
	if(t1==t2 && q==0) cout<<1<<" ";
	else 
	{
		cout<<0<<" ";
		w=1;
	}
	if(((s3<=3 && s4<=3) || (s3>=4 && s4>=4)) && w==0) cout<<1<<" ";
	else 
	{
		cout<<0<<" ";
		p=1;
	}
	if((s4-s3==1 || s3-s4==1) && p==0) cout<<1<<" ";
	else cout<<0<<" ";
	return 0;
}
