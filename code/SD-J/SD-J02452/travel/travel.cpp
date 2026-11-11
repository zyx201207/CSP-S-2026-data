#include<bits/stdc++.h>
using namespace std;
char cr[5],sr[5],cx[5],sx[5],ans[5]={0};
void shuchu()
{
	for(int i=1;i<=4;i++)
	{
		if(ans[i]!='1')
		{
			for(int j=i;j<=4;j++)
				cout<<'0';
			return;
		}
		else
			cout<<'1';
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>cr>>sr>>cx>>sx;
	int xiang=0,hang=0;
	for(int i=0;i<2;i++)
	{
		if(cr[i]!=cx[i])
			xiang=1;
		if(sr[i]!=sx[i])
			hang=1;
	}
	if(xiang==0)
		ans[1]='1';
	else
	{
		ans[1]='0';
		shuchu();
		return 0;
	}
	if(hang==0)
		ans[2]='1';
	else
	{
		ans[2]='0';
		shuchu();
		return 0;
	}
	if(((sr[2]=='A'||sr[2]=='B'||sr[2]=='C')&&(sx[2]=='A'||sx[2]=='B'||sx[2]=='C'))||((sr[2]=='D'||sr[2]=='F')&&(sx[2]=='D'||sx[2]=='F')))
		ans[3]='1';
	else
	{
		ans[3]='0';
		shuchu();
		return 0;
	}
	if((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='D'&&sx[2]=='F')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='C'&&sx[2]=='B')||(sr[2]=='F'&&sx[2]=='D'))
		ans[4]='1';
	else
	{
		ans[4]='0';
		shuchu();
		return 0;
	}
	shuchu();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
