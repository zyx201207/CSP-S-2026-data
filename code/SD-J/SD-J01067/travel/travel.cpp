#include<bits/stdc++.h>
using namespace std;
char c[20];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++)
		cin>>c[i];	
	if(c[1]==c[6]&&c[2]==c[7])
	{
		cout<<1;
		if(c[3]==c[8]&&c[4]==c[9])
		{
			cout<<1;
			if((c[5]<='C'&&c[10]<='C')||(c[5]>='D'&&c[10]>='D'))
			{
				cout<<1;
				if(abs(max(int(c[5]),int(c[10]))-1)==min(int(c[5]),int(c[10])))
					cout<<1;
				else cout<<0;	
			}
			else
				cout<<0<<0;
		}
		else
			cout<<0<<0<<0;
	}	
	else 
		cout<<0<<0<<0<<0;		
	return 0;
} 
