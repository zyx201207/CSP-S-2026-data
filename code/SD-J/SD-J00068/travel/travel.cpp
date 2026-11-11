#include<iostream>
#include<cstdio>
using namespace std;
struct seat
{
	int xiang,pai,wei;
};
string s[4];
seat n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s[0]>>s[1]>>s[2]>>s[3];
	n.xiang=(s[0][0]-'0')*10+(s[0][1]-'0');
	n.pai=(s[1][0]-'0')*10+(s[1][1]-'0');
	n.wei=s[1][2]-'A'+1;
	m.xiang=(s[2][0]-'0')*10+(s[2][1]-'0');
	m.pai=(s[3][0]-'0')*10+(s[3][1]-'0');
	m.wei=s[3][2]-'A'+1;
	if(n.xiang==m.xiang)
	{
		if(n.pai==m.pai)
		{
			if((n.wei<=3 && m.wei<=3) || (n.wei>3 && m.wei>3))
			{
				if(abs(n.wei-m.wei)==1 || (n.wei>3 && m.wei>3)) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
