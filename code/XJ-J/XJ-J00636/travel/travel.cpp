#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,e;
int f,j;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	f=(int)b[2];
	j=(int)d[2];
	if(a==c)
	{
		e[0]='1';
		for(int i=0;i<2;i++)//*
		{
			if(b[i]==d[i])
			{
				e[1]='1';
				if(f<=67&&j<=67)//*
				{
					e[2]='1';
					if(f-j==1||j-f==1)
					{
						e[3]='1';
					}
					else
					{
						e[3]='0';
					}
				}
				else if(f>67&&j>67)//*
				{
					e[2]='1';
					if(f-j==2||j-f==2)
					{
						e[3]='1';
					}
					else{
						e[3]='0';
					}
				}
				else
				{
					for(int i=2;i<4;i++)
					{
						e[i]='0';
					}
				}
			}
			else
			{
				for(int i=1;i<4;i++)
				{
					e[i]='0';
				}
			}
		}
	}
	else{
		for(int i=0;i<4;i++)
		{
			e[i]='0';
		}	
	}
	for(int i=0;i<4;i++)
	{
		cout<<e[i];
	}
	return 0;
}