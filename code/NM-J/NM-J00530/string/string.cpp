#include<bits/stdc++.h>
using namespace std;
string s="",v,z="";
long long n,f,m=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>f>>v;
		for(long long j=1;j<=f;j++)
			s=s+v;
	}
	z=s;
	reverse(s.begin(),s.end());
	if(z==s) {cout<<0;return 0;}
	long long c=s.size(),x=0,y=c-1;
	for(long long i=0;i<=c/2;i++)
	{
		if(s[x]!=s[y]) {m++;s[y]=s[x];} 
		x++;
		y--;
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
