#include <bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int sum[5][18];
	int c[4]={0,0,0,0};
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<18;j++)
		{
			if(c1==c2)
	        {
	        	c[0]=1;
        	}
			if(s1=='i'&&s2=='i')
			{
				c[1]=1;
			}
			if(s1=='A'||'B'||'C')
			{
				if(s2='A'||'B'||'C')
				{
					c[2]==1;
				}
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
