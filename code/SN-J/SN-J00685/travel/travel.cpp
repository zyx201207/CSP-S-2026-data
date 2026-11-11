//xinzizhang SN-J00685
//xi'an JiaoTongdaxuefushuzhongxue
#include <bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
char s11,s22;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) 
	{
		cout<<1;
		if(s1[1]==s2[1] && s1[0]==s2[0]){
			cout<<1;
			s11=char(s1[2]);
			s22=char(s2[2]);
			if((s11<='C' && s22<='C')||(s11>'C' && s22>'C')) {
				cout<<1;
				if(s11-s22==1 || s11-s22==-1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
			
		}
		else cout<<0<<0<<0;
		
	}
	else cout<<0<<0<<0<<0;
	
	return 0;
}
