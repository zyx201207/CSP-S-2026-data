#include<bits/stdc++.h>
using namespace std;
char a[5][4];
int b[5],c,d,e,f,g,h;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	c=(a[1][0]-'0')*10+(a[1][1]-'0');
	d=(a[2][0]-'0')*10+(a[2][1]-'0');
	e=(a[3][0]-'0')*10+(a[3][1]-'0');
	f=(a[4][0]-'0')*10+(a[4][1]-'0');
	if(a[2][2]=='A'||a[2][2]=='B'||a[2][2]=='C')
		g=1;
	else 
		g=0;
	if(a[4][2]=='A'||a[4][2]=='B'||a[4][2]=='C')
		h=1;
	else 
		h=0;
	if(c==e)
		b[1]=1;
	else
		b[1]=0;
	if(d==f&&b[1]==1)
		b[2]=1;
	else
		b[2]=0;
	if(g==h&&b[2]==1)
		b[3]=1;
	else
		b[3]=0;
	if(b[3]==1&&(g==0||(a[2][2]=='A'&&a[4][2]=='B')||(a[2][2]=='B'&&a[4][2]=='C')||(a[2][2]=='B'&&a[4][2]=='A')||(a[2][2]=='C'&&a[4][2]=='B')))
		b[4]=1;
	else
		b[4]=0;
	for(int i=1;i<=4;i++)
		cout<<b[i];
	return 0;
}
