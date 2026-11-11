#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=1e6+1000,M2=1e3+100;
string c1,s1,c2,s2;
lint a[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F') s1[2]='E';
	if(s2[2]=='F') s2[2]='E';
	if(c1==c2) a[1]=1;
	else a[1]=0;
	if(s1[1]==s2[1]&&s1[0]==s2[0]&&a[1]==1) a[2]=1;
	else a[2]=0;
	if(a[2]==1&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))) a[3]=1;
	else a[3]=0;
	if(a[3]==1&&(s1[2]-s2[2])*(s1[2]-s2[2])==1) a[4]=1;
	else a[4]=0;
	for(lint i=1;i<=4;i++) cout<<a[i];
	return 0;
}
