#include<bits/stdc++.h>
#define ll long long
#define N 1
char c1[3],s1[3],c2[3],s2[3];
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]&&c1[0]==c2[0])
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	char a=s1[2],b=s2[2];
	if(((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))||((a=='D'||a=='F')&&(b=='D'||b=='F')))
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if((a=='D'&&b=='F')||(a=='F'&&b=='D'))
		cout<<1;
	else if(abs(a-b)==1)
		cout<<1;
	else
		cout<<0;
	return 0;
}
