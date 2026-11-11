#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int f,m,a,b,cmt=0,tmc=0,bot=0,h=0;
	cin>>f>>m;
	cin>>a>>b;
	h=b;
	int n[a];
	cin>>n[a];
	for(int l=0;l<=a;l+=b)
	{
		if(a-l<b)
		{
			for(int i=1;b<=a-l;i++)
			{
				b--;
			}
		}
		cmt++;
	}
	for(int r=a;r>=0;r-=b)
	{
		while(b>=1)
		{
			b--;
		}
		b=h;
		tmc++;
		if(cmt==tmc)
		{
			bot++;
		}
	}
	cout<<bot;
	return 0;
}
