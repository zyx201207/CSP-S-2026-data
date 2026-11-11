#include<bits/stdc++.h>
using namespace std;
int n,x,y;
string a,b;
int f(char x)
{
	if(x=='A'||x=='B'||x=='C') return 1;
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x==y) printf("1");
	else printf("0");
	if(x==y&&a[0]==b[0]&&a[1]==b[1])
		printf("1");
	else printf("0");
	if(x==y&&a[0]==b[0]&&a[1]==b[1]&&f(a[2])==f(b[2]))
		printf("1");
	else printf("0");
	if(x==y&&a[0]==b[0]&&a[1]==b[1]&&f(a[2])==f(b[2])&&(abs(a[2]-b[2])==1||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')))
		printf("1");
	else printf("0");
	return 0;
}
/*
02 01D 02 01F
*/
