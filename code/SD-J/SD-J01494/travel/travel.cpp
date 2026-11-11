#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string cx,lx,cy,ly;
char ans[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>lx>>cy>>ly;
	for(long long i=1; i<=4; i++)
		{
			ans[i]='0';
		}
	if(cx==cy)
		{
			ans[1]='1';
			bool ok=1;
			for(long long i=0; i<lx.size(); i++)
				{
					if(lx[0]==ly[0]&&lx[1]==ly[1])
						{
							ok=1;
						}
					else
						{
							ok=0;
						}
					if(ok==1)
						{
							ans[2]='1';
							if(i==2)
								{
									if((lx[i]=='A'&&(ly[i]=='B'||ly[i]=='C'))||(lx[i]=='B'&&(ly[i]=='A'||ly[i]=='C'))||(lx[i]=='C'&&(ly[i]=='A'||ly[i]=='B'))||(lx[i]=='D'&&(ly[i]=='F'))||(lx[i]=='F'&&(ly[i]=='D')))
										{
											ans[3]='1';
											if((lx[i]=='A'&&(ly[i]=='B'))||(lx[i]=='B'&&(ly[i]=='A'||ly[i]=='C'))||(lx[i]=='C'&&(ly[i]=='B'))||(lx[i]=='D'&&(ly[i]=='F'))||(lx[i]=='F'&&(ly[i]=='D')))
												{
													ans[4]='1';
												}
										}
								}
						}
				}
		}
	for(long long i=1; i<=4; i++)
		{
			cout<<ans[i];
		}
	cout<<endl;
	return 0;
}
