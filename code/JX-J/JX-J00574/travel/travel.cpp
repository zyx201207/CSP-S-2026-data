#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xc,xs,yc,ys;
	cin>>xc>>xs>>yc>>ys;
	if(xc==yc)
	{
		cout<<"1";
		if(xs[0]==ys[0]&&xs[1]==ys[1])
		{
			cout<<"1";
			if((xs[2]-64<=3&&xs[2]-64>=0&&ys[2]-64<=3&&xs[2]-64>=0)||(xs[2]-64<=6&&xs[2]-64>=4&&ys[2]-64<=6&&ys[2]-64>=4))
			{
				cout<<"1";
				if((xs[2]-64<=3&&xs[2]-64>=0&&ys[2]-64<=3&&xs[2]-64>=0)||(xs[2]-64<=6&&xs[2]-64>=4&&ys[2]-64<=6&&ys[2]-64>=4))
				{	
					if(xs[2]+1==ys[2]||xs[2]-1==ys[2])
					{
						cout<<"1";
					}
					else
					{
						cout<<"0";
					}
				}
			}
			else
			{
				cout<<"00";
				
			}
		}
		else
		{
			cout<<"000";
			
		}
	}
	else
	{
		cout<<"0";
		if(xs[0]==ys[0]&&xs[1]==ys[1])
		{
			cout<<"0";
			if((xs[2]-64<=3&&xs[2]-64>=0&&ys[2]-64<=3&&xs[2]-64>=0)||(xs[2]-64<=6&&xs[2]-64>=4&&ys[2]-64<=6&&ys[2]-64>=4))
			{
				cout<<"0";
				if((xs[2]-64<=3&&xs[2]-64>=0&&ys[2]-64<=3&&xs[2]-64>=0)||(xs[2]-64<=6&&xs[2]-64>=4&&ys[2]-64<=6&&ys[2]-64>=4))
				{	
					if(xs[2]+1==ys[2]||xs[2]-1==ys[2])
					{
						cout<<"0";
					}
					else
					{
						cout<<"0";
					}
				}
			}
			else
			{
				cout<<"00";
				
			}
		}
		else
		{
			cout<<"000";
			
		}
	}
	return 0;
}
