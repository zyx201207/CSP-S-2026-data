#include<bits/stdc++.h>
using namespace std;
string t;
long long a,s[10086],d=0,f,h;
char g[10086];

void p(long long pp,long long z)
{
	
if(pp>=z) return;
	if(g[pp]!=g[z]) 
	{
	
			d+=min(s[pp],s[z]);
			if(s[pp]>s[z]) s[pp]-=s[z];
			else s[z]-=s[pp];
}
if(max(s[pp],s[z])==0)
p(pp+1,z-1);
else 
{
if(s[pp]>s[z]) p(pp,z-1);
else p(pp+1,z);
}
}
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>a;
for(int i=0;i<a;i++)
{
	cin>>s[i]>>g[i];
	h+=s[i];
	
}
p(0,a-1);
cout<<d;

return 0;
}
