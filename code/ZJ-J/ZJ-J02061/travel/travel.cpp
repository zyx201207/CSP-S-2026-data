#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans=1;
	if (c1!=c2) ans=0;
	cout<<ans;
	if (s1[0]!=s2[0]||s1[1]!=s2[1]) ans=0;
	cout<<ans;
	if ((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C')) ans=0;
	cout<<ans;
	if (abs(s1[2]-s2[2])!=1) ans=0;
	cout<<ans;
	return 0;
}
