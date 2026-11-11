#include<bits/stdc++.h>
using namespace std;
string a1,a2;
int x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a1>>y>>a2;
	if(x==y)
	{
		cout<<1;
		int aa[5],bb[5];
		aa[0]=a1[0]-'0',bb[0]=a2[0]-'0';
		aa[1]=a1[1]-'0',bb[1]=a2[1]-'0';
		char xx=a1[2],yy=a2[2];
		if(aa[0]==bb[0]&&aa[1]==bb[1])
		{
			cout<<1;
			if((xx!='D'&&xx!='F'&&yy!='D'&&yy!='F')||((xx=='D'||xx=='F')&&(yy=='D'||yy=='F')))
			{
				cout<<1;
				if(abs(int(xx)-int(yy))==1&&((xx!='D'&&yy!='C')||(xx!='D'&&yy!='D'))||((xx=='F'&&yy=='D')||(xx=='D'&&yy=='F')))
				{
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		} 
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
 
