//1
#include<bits/stdc++.h>
using namespace std;
//#define int long long
string c1,s1,c2,s2;
int vis[10]={1,1,1,2,2};
int f(char a,char b)
{
	if(a>b) swap(a,b);
	if(a=='A' && b=='B') return 1;
	else if(a=='B' && b=='C') return 1;
	else if(a=='D' && b=='F') return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout<<1;
			if(vis[s1[2]-'A']==vis[s2[2]-'A'])
			{
				cout<<1;
				if(f(s1[2],s2[2])) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}