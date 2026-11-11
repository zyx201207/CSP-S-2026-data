#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int c1,c2;
	char s1[3],s2[3];
	cin>>c1;
	for(int i=0;i<3;++i) cin>>s1[i];
	cin>>c2;
	for(int i=0;i<3;++i) cin>>s2[i];
	int val,va;
	if(s1[2]=='A') val=1;
	if(s1[2]=='B') val=2;
	if(s1[2]=='C') val=3;
	if(s1[2]=='D') val=4;
	if(s1[2]=='E') val=5;
	if(s2[2]=='A') va=1;
	if(s2[2]=='B') va=2;
	if(s2[2]=='C') va=3;
	if(s2[2]=='D') va=4;
	if(s2[2]=='E') va=5;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if((va>=1&&va<=3&&val>=1&&val<=3)||(val>=4&&val<=5&&va>=4&&va<=5))
			{
				cout<<1;
				if(max(va-val,val-va)==1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
