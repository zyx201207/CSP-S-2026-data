#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) f[0]=true;
	if(f[0]&&(s1[0]==s2[0]&&s1[1]==s2[1])) f[1]=true;
	if(f[1]&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))) f[2]=true;
	if(f[2]&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1)) f[3]=true;
	for(int i=0;i<4;i++)
	{
		if(f[i]) cout<<1;
		else cout<<0;
	}
	return 0;
}
