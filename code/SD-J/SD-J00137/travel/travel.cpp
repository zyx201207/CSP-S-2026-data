#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,t1,t2;
bool flag1,flag2,flag3,flag4,f[152][152];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) flag1=1;
	else flag1=0;
	t1=s1.substr(0,2);
	t2=s2.substr(0,2);
	if(flag1&&t1==t2) flag2=1;
	else flag2=0;
	f['A']['B']=1,f['A']['C']=1,f['A']['A']=1;
	f['B']['A']=1,f['B']['C']=1,f['B']['B']=1;
	f['C']['A']=1,f['C']['B']=1,f['C']['C']=1;
	f['D']['D']=1,f['D']['F']=1;
	f['F']['D']=1,f['F']['F']=1;
	if(flag2&&f[s1[2]][s2[2]]) flag3=1;
	else flag3=0;
	if(flag3&&abs(s1[2]-s2[2])==1) flag4=1;
	else flag4=0;
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
