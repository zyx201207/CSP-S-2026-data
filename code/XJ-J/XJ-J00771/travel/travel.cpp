#include<bits/stdc++.h>
using namespace std;
int main()
    {
    	freopen("travel.in","r",stdin);
    	freopen("travel.out","w",stdout);
    	string c1,s1,c2,s2;
    	int d,t,n,b;
    	cin >> c1 >> s1 >> c2 >> s2;
    	if(c1=="02")
    	{
    		d=1;
		}
		else
		{
			d=0;
		}
		if(c2=="02")
    	{
    		t=1;
		}
		else
		{
			t=0;
		}
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			n=1;
		}
		else
		{
			n=0;
		}
		if(s1[2]==s2[2]+1||s2[2]==s1[2]+1)
		{
			if(s1[2]=='D'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='C')
			{
				b=0;
			}
			b=1;
		}
		else
		{
			b=0;
		}
		cout << d << n << t << b;
		return 0;
	}