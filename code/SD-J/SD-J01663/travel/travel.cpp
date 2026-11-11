#include<iostream>
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
int c,s;
char a[80][3];
int main()
{
	CLOSE
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	a['A'][1]='B';
	a['B'][1]='A',a['B'][2]='C';
	a['C'][1]='B',a['C'][2]='G';
	a['D'][1]='G',a['D'][2]='F';
	a['F'][1]='D';
	if(c1!=s1)
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		c*=10;
		c+=c2[i];
		s*=10;
		s+=s2[i];
	}
	if(c!=s)
	{
		cout<<"1000";
		return 0;
	}
	if((s2[2]>='A'&&s2[2]<='C'&&(c2[2]=='D'||c2[2]=='F'))||(c2[2]>='A'&&c2[2]<='C'&&(s2[2]=='D'||s2[2]=='F')))
	{
		cout<<"1100";
		return 0;
	}
	int f=0;
	for(int i=1;i<=2;i++)
	{
		if(a[c2[2]][i]==s2[2])
		{
			f=1;
		}
	}
	if(f==1) cout<<"1111";
	else cout<<"1110";
	return 0;
}
