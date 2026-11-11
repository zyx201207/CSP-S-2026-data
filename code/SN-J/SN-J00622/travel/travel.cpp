#include<bits/stdc++.h>
using namespace std;
char c1[2],s1[3],c2[2],s2[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int id[]={1,1,1,0,0,0};
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if(id[s1[2]-'A']==id[s2[2]-'A']) cout<<"1";
	else 
	{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) cout<<"1";
	else cout<<"0";
	return 0;
}
