#include<bits/stdc++.h>
using namespace std;
bool pd(char a,char b)
{
	int x=1,y=1;
	if(a>'C')x=2;
	if(b>'C')y=2;
	return x==y;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char x1,x2,y1,y2,y3,x3,c1,c2,c3,c4;
	cin>>c1>>c2>>x1>>x2>>x3>>c3>>c4>>y1>>y2>>y3;
	if(c1==c3&&c2==c4)
	{
		cout<<"1";
		if(x1==y1&&x2==y2)
		{
			cout<<"1";
			if(x3=='C'&&y3=='D')cout<<"00";
			else if(y3=='C'&&x3=='D')cout<<"00";
			else if(pd(x3,y3))
			{
				cout<<"1";
				if(abs(x3-y3)==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
