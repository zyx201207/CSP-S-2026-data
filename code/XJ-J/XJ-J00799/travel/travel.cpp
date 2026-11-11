#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;



int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans[5]={1,0,0,0,0};
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans[1]=1;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0])
	{
		ans[2]=1;
	}
	if(s1[2]>='A'&&s2[2]<='C'||s1[2]>='E'&&s2[2]<='E')
	{
		ans[3]=1;
	}
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
	{
		ans[4]=1;
	}
	for(int a=1;a<=4;a++)
	{
		if(ans[a-1]==0)
			ans[a]=0;
	}
	for(int a=1;a<=4;a++)
	{
		cout<<ans[a];
	}
	return 0;
}