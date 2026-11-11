#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,l;
int e[6]={1,1,1,2,0,2};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		l+='1';
		if(b[0]==d[0]&&b[1]==d[1])
		{
			l+='1';
			if(e[b[2]-'A']==e[d[2]-'A'])
			{
				l+='1';
				if((e[b[2]-'A']==1&&abs(b[2]-'A'-d[2]+'A')==1)||e[b[2]-'A']==2)
					l+='1';
			}
		}
	}
	for(int i=1;i<=4;i++)
		l+='0';
	for(int i=0;i<4;i++)
		cout<<l[i];
	return 0;
 } //AC
