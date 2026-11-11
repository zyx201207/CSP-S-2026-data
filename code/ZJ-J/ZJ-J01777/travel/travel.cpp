#include<bits/stdc++.h>
using namespace std;
string a,aa,b,bb;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>aa>>b>>bb;
	if(a==b)
	{
		cout<<"1";
		int x=int(aa[0]-'0')*10+int(aa[1]-'0'),y=int(bb[0]-'0')*10+int(bb[1]-'0');
		if(x==y)
		{
			cout<<"1";
			if((aa[2]>='A'&&aa[2]<='C'&&bb[2]>='A'&&bb[2]<='C')||(aa[2]>='D'&&aa[2]<='E'&&bb[2]>='D'&&bb[2]<='E'))
			{
				cout<<"1";
				int xx=int(aa[2]-'A')+1,yy=int(bb[2]-'A')+1;
				if(abs(xx-yy)==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}