#include <bits/stdc++.h>
using namespace std;
string r2,x2;//小 R 的车票上的车厢号、座位号
string r1,x1;  //小 X 的车票上的车厢号、座位号
int cx(string a,string b)
{
	if(a==b)return 1;
	else return 0 ;
}
int ps(string c,string d)
{
	if(cx(r1,x1)==0)return 0;
	char rp=c[0]+c[1];//r排数
	char xp=d[0]+d[1];//x排数 
	if(xp==rp)return 1;
	else return 0;	
}
int tc(string e,string f)
{
	if(cx(r1,x1)==0)return 0;
	if(ps(r2,x2)==0)return 0;
	if((e[2]=='A'&&f[2]=='D')
	||(e[2]=='B'&&f[2]=='D')
	||(e[2]=='C'&&f[2]=='D')
	||(e[2]=='D'&&f[2]=='A')
	||(e[2]=='D'&&f[2]=='B')
	||(e[2]=='D'&&f[2]=='C')
	||(e[2]=='A'&&f[2]=='F')
	||(e[2]=='B'&&f[2]=='F')
	||(e[2]=='C'&&f[2]=='F')
	||(e[2]=='F'&&f[2]=='A')
	||(e[2]=='F'&&f[2]=='B')
	||(e[2]=='F'&&f[2]=='C'))return 0;
	else return 1; 
} 
int xl(string g,string h)
{
	if(cx(r1,x1)==0)return 0;
	if(tc(r2,x2)==0)return 0;
	if(g[2]-h[2]==1||h[2]-g[2]==1)return 1;
	else return 0; 
} 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;//r1:r的车厢，r2:r的座位号 x1:r的车厢，x2:r的座位号 
	cout<<cx(r1,x1)<<ps(r2,x2)<<tc(r2,x2)<<xl(r2,x2);
	return 0;
}

