#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int r,x;
bool c,s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	for(int i=0;i<2;i++)
	{
		r=r*10+sr[i]-'0';
		x=x*10+sx[i]-'0';
	}
	if((sr[2]-'A')<3) c=false;
	else c=true;
	if((sx[2]-'A')<3) s=false;
	else s=true;

	if(cr==cx)cout<<1;
	else cout<<0;

	if(cr==cx&&x==r)cout<<1;
	else cout<<0;

	if(cr==cx&&x==r&&c==s)cout<<1;
	else cout<<0;

	if(abs(sx[2]-sr[2])==1&&cr==cx&&x==r&&c==s)cout<<1; 
	else cout<<0;
	
	return 0;
} 
