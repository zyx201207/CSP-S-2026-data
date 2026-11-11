#include<bits/stdc++.h>
using namespace std;
int box(int c1,int x1,string c2,string x2)
{
	if(c1==x1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int tongyipai(int c1,int x1,string c2,string x2)
{
	if(int(c2[0])+int(c2[1])==int(x2[0])+int(x2[1]))
	{
		return true;
    }
	else
	{
		return false;
	}
}
int tongyice(int c1,int x1,string c2,string x2)
{
	if(int(c2[2])==65)
	{
		if(int(x2[2])==66||int(x2[2])==67) return true;
	}
	else if(int(c2[2])==66)
	{
		if(int(x2[2])==65||int(x2[2])==67) return true;
	}
	else if(int(c2[2])==67)
	{
		if(int(x2[2])==65||int(x2[2])==66) return true;
	}
	else if(int(c2[2])==68)
	{
		if(int(x2[2])==70) return true;
	}
	else if(int(c2[2])==70)
	{
		if(int(x2[2])==68) return true;
	}
	else
	{
		return false;
	}
}
int near(int c1,int x1,string c2,string x2)
{
	if(int(c2[2])==65)
	{
		if(int(x2[2])==66) return true;
	}
	else if(int(c2[2])==66)
	{
		if(int(x2[2])==65||int(x2[2])==67) return true;
	}
	else if(int(c2[2])==67)
	{
		if(int(x2[2])==66) return true;
	}
	else if(int(c2[2])==68)
	{
		if(int(x2[2])==70) return true;
	}
	else if(int(c2[2])==70)
	{
		if(int(x2[2])==68) return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,x1;
	string c2,x2;
	cin>>c1;
	cin>>c2;
	cin>>x1;
	cin>>x2;
	if(box(c1,x1,c2,x2))
	{
		cout<<"1";
		if(tongyipai(c1,x1,c2,x2))
		{
			cout<<"1";
			if(tongyice(c1,x1,c2,x2))
			{
				cout<<"1";
				if(near(c1,x1,c2,x2 ))
			    {
				    cout<<"1";
			    }
			    else
			    {
			    	cout<<"0";
				}
			}
			else
			{
			    cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
	
}
