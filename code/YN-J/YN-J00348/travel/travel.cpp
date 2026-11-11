#include <bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
bool flago=false,flagt=false,flagh=false,flagf=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> rc >> rs >> xc >> xs;
	if(rc!=xc)
	{
		cout << "0000";
		return 0;
	}
	else
	{
		flago=1;
		for(int i=0;i<2;i++)
		{
			if(rs[i]!=xs[i])
			{
				flagt=1;
				flagh=1;
				break;
			}	
		}
		if(!flagh)
		{
			if((rs[2]>='A'&&rs[2]<='C'&&xs[2]>='A'&&xs[2]<='C')||(rs[2]>='D'&&rs[2]<='F'&&xs[2]>='D'&&xs[2]<='F'))
			{
				flagh=0;
			}
			else
			{
				flagh=1;
			}
	    }
	}
	if(!flagt&&!flagh)
	{
		if((rs[2]>='A'&&rs[2]<='C'&&xs[2]>='A'&&xs[2]<='C'))
		{
			if((rs[2]+1==xs[2]||rs[2]-1==xs[2]))
			{
				flagf=1;
			}
			else
			{
				if((rs[2]>='D'&&rs[2]<='F'&&xs[2]>='D'&&xs[2]<='F'))
				{
					flagf=1;
				}
			}
	    }
	}
	if(!flago)
	{
		cout <<0;
	}
	else
	{
		cout <<1;
	}
	if(!flagt)
	{
		cout <<1;
	}
	else
	{
		cout << 0;
	}
	if(!flagh)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(flagf)
	{
		cout << 1;
	}
	else
	{
		cout <<0;
	}
    return 0;
}
