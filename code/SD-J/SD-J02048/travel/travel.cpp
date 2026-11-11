#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<stack>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1,r2,x1,x2,r4,x4;
	char r3,x3;
	cin>>r1>>r2>>r3>>x1>>x2>>x3;
	if(r3=='A'||r3=='B'||r3=='C')    r4=1;
	else    r4=2;
	if(x3=='A'||x3=='B'||x3=='C')    x4=1;
	else    x4=2;
	if(r1!=x1)    cout<<"0000";
	else
	{
		cout<<"1";
		if(r2!=x2)    cout<<"000";
		else
		{
			cout<<"1";
			if(r4!=x4)    cout<<"00";
			else
			{
				cout<<"1";
				int s=abs((int)(r3-x3));
				if(s!=1||(r3=='C'&&x3=='D')||(r3=='D'&&x3=='C'))    cout<<"0";
				else    cout<<"1";
			}
		}
	}
	return 0;
}

