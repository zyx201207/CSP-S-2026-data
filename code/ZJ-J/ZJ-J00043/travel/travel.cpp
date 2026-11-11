#include<bits/stdc++.h>
using namespace std;
int judge(char a)
{
	if(a=='A' || a=='B' || a=='C') return 0;
	return 1;
}
int main()
{	 
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	char c1[3],s1[4],c2[3],s2[4];
	cin>>c1>>s1>>c2>>s2;
	bool flag[5];
	for(int i=0;i<5;i++)
		flag[i] = false;
	if(c1[0] == c2[0] && c1[1]==c2[1])
		flag[1] = true;
	if(flag[1] && s1[0] == s2[0] && s1[1] == s2[1])
		flag[2] = true;
	if(flag[2] && judge(s1[2]) == judge(s2[2]))
		flag[3] = true;
	if(flag[3])
	{
		flag[4]=true;
		if(judge(s1[2])==0)
		{
			if(s1[2] == 'A' && s2[2] == 'C')
				flag[4]=false;
			if(s1[2] == 'C' && s2[2] == 'A')
				flag[4]=false;
		}
	}
	for(int i =1;i<=4;i++)
		if(flag[i]) cout<<1;
		else cout<<0;
	return 0;
}
