#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char x[5],x1[5];
	string r;
    cin>>r;
    for(int i=1;i<=3;i++)
    {
    	cin>>x[i];
    	
	}
    string r1;
    cin>>r1;
    for(int i=1;i<=3;i++)
    {
    	cin>>x1[i];
    	
	}
	if(r==r1)
	{
		cout<<"1";
		if(x[1]==x1[1] && x[2]==x1[2])
		{
			cout<<"1";
			if((x[3]<=67 && x1[3]<=67) || (x[3]>67 && x1[3]>67))
			{
				cout<<"1";
				if((int(x[3])-int(x1[3])==1 || int(x1[3])-int(x[3])==1) ||x[3]>67)
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
    
	
	
    return 0;
	
	
} 
