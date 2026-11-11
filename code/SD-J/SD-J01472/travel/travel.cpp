#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a,c;
	char b,d;
    string x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int x,y;
    a=y1.substr(0,2);
    b=y1[2];
	c=y2.substr(0,2);
	d=y2[2];
    if(x1==x2)
    {
    	cout<<"1";
    	if(a==c)
    	{
    		cout<<"1";
    		if((b=='A'&&(d=='B'||d=='C'))||
			   (b=='B'&&(d=='A'||d=='C'))||
			   (b=='C'&&(d=='A'||d=='B'))||
			   (b=='D'&&(d=='F'))||
			   (b=='F'&&(d=='D')))
			{
				cout<<"1";
				x=b-'A';
				y=d-'A';
				if(abs(x-y)==1)
				  cout<<"1";
				else
				  cout<<"0";
			}
			else
			  cout<<"00";
		}
		else
		  cout<<"000";
	}
	else
	  cout<<"0000";
	return 0;
}

