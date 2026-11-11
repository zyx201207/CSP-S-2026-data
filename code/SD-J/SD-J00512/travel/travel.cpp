#include <bits/stdc++.h>
using namespace std;
int c[10],i;
string s1,s2;
bool f[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s1>>c[2]>>s2;
	if(c[1]==c[2]) f[1]=1;
	int a=s1[1]-'0';int b=s2[1]-'0';
	if(f[1]&&a==b) f[2]=1;
	if(f[1]&&f[2]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))
		f[3]=1;
	if(f[1]&&f[2]&&f[3]&&(s1[2]+1==s2[2]||s1[2]-1==s2[2]))
		f[4]=1;
	for(i=1;i<=4;i++)
	{
		cout<<f[i];
	}
	return 0;
} 
