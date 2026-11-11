#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int n,a;
	string m,b;
	cin>>n>>m>>a>>b;
	bool t=0;
	if (n==a)
	{
		cout<<1;
		t=1;
	}
	else{
		cout<<0<<0<<0<<0;
	}
	if (t==1)
	{
		if (m[0]==b[0]&&m[1]==b[1])
	    {
	    	cout<<1;
	    }
	    else if (m[0]!=b[0]||m[1]!=b[1])
	    {
    		cout<<0<<0<<0;
    		t=0;
	    }
	}
	if (t==1)
	{
		if ((m[2]>'C'&&b[2]>'C')||(m[2]<='C'&&b[2]<='C'))
	    {
	    	cout<<1;
	    }
	    else if((m[2]<'C'&&b[2]>='C')||(m[2]>='D'&&b[2]<'D')||(m[2]>'C'&&b[2]<='C')||(m[2]<'D'&&b[2]>='D'))
	    {
	    	cout<<0<<0;
	    	t=0;
	    }
	    
	}
	if (t==1)
	{
		if ((m[2]==b[2]+1)||(m[2]+1==b[2]))
	    {
	    	cout<<1;
        }
	    else
	    {
		cout<<0;
	    }
	}
}
