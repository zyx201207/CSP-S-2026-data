#include <bits\stdc++.h>
using namespace std;
int answer[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4; 
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1==c3)
	{
		answer[0]=1;
		if (c2[1]==c4[1])
		{
			answer[1]=1;
			if(((c2[2]<='C' && c4[2]<='C') || (c2[2]>='D' && c4[2]>='D')))
			{
				answer[2]=1;
				if((c2[2]-c4[2]+'B')=='A' || (c2[2]-c4[2]+'B')=='C')
				{
					answer[3]=1;
				}
			}
		}
	}
	for(int i=0;i<=3;i++)
	{
		cout << answer[i];
	}
	
	
	return 0;
}
