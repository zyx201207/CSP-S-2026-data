#include<bits/stdc++.h>
using namespace std;
int n,m;
string c,s;
bool f1=false,f2=false,f3=false,f4=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	cin>>c;
	cin>>m;
	cin>>s;
	if(n==m) f1=true;
	if(f1)
	{
		if(c[0]==s[0]&&c[1]==s[1]) f2=true;
		if(f2)
		{
			if((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(s[2]=='A'||s[2]=='B'||s[2]=='C')) f3=true;
			if((c[2]=='D'||c[2]=='E')&&(s[2]=='D'||s[2]=='E')) f3=true;
			if(f3)
			{
				if(s[2]==c[2]+1||s[2]==c[2]-1) f4=true;
			}
		}
	}
	if(f1) cout<<1;
	else cout<<0;
	if(f2) cout<<1;
	else cout<<0;
	if(f3) cout<<1;
	else cout<<0;
	if(f4) cout<<1;
	else cout<<0;
	return 0;
} 
