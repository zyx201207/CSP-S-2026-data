#include<bits/stdc++.h> 
using namespace std;
int main()
{
	feropen('travelin','w','stdin');
	feropen('travelout','r','stdout');
	int x,p;
	int x1,p1;
	char z,z1;
	cin >> x >> p >> z;
	cin >> x1 >> p1  >> z1;
	for(int i = 1;i <= 17;i++)
	{
		if(x==x1)
		{
			cout << 1;
			break;
		} 
		else
		{
			cout << 0;
			break;
		}
	} 
	for(int i = 1;i <= 18;i++)
	{
		if(p==p1)
		{
			cout << 1;
			break;
		}
		else
		{
			cout << 0;
			break;
		}
	}
	
	for(int i = 'A';i <= 'F';i++)
	{
		if((z=='A' && z1=='B')||(z=='B' && z1=='C')||(z=='A' && z1=='C'))
		{
			cout << 1;
			break;
		}
		else
		{
			if(z=='D' && z1=='F')
			{
				cout << 1;
				break;
			}
			else
			{
				cout << 0;
				break;
			}
		}
	}
	for(int i = 'A';i <= 'F';i++)
	{
		if(z-z1==1 || z1-z==1)
		{
			cout << 1;
			break;
		}
		else
		{
			cout << 0;
			break;
		}
	}
	return 0;
 } 
