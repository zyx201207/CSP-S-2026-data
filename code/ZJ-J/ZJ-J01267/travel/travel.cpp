#include<bits/stdc++.h>
using namespace std;
char n[3],m[3],c[4],s[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",n+1,c+1,m+1,s+1);
	int a=n[1]-'0',b=n[2]-'0',p=m[1]-'0',q=m[2]-'0';
	if(a==p&&b==q) cout<<1;
	else 
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int v[4],t[4];
	for(int i=1;i<=3;i++) v[i]=c[i]-'0',t[i]=s[i]-'0';
	if(v[1]==t[1]&&v[2]==t[2]) cout<<1;
	else 
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(v[3]<t[3]) swap(v[3],t[3]);
	bool flag=0;
	if((v[3]>=20&&t[3]>=20)||(v[3]<=19&&t[3]<=19)) flag=1,cout<<1;
	else cout<<0;
	if(flag==1&&v[3]-t[3]<=1) cout<<1;
	else cout<<0;
	return 0;
}