#include<bits/stdc++.h>
using namespace std;
long long int x1,x2;
string a,b,c,d;
string aa,bb;
int main()
{	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>aa>>c>>bb;
    if(a==c)
    {
    	cout<<1;
    	x1=(aa[0]-'0')*10+aa[1]-'0';
    	x2=(bb[0]-'0')*10+bb[1]-'0';
    	if(x1==x2)
    	{
    		cout<<1;
    		if(aa[2]>='A'&&aa[2]<='C'&&bb[2]>='A'&&bb[2]<='C'||aa[2]>'C'&&bb[2]>'C')
    		
    		{cout<<1;
    			if(aa[2]-bb[2]==1||bb[2]-aa[2]==1)
    			{
    				if(aa[2]!='C'&&bb[2]!='D'||aa[2]!='D'&&bb[2]!='C')
    				cout<<1;
					else
				    cout<<0;
				}
				else
				cout<<0;
			}
			    else
				cout<<0;
		}
		else
				cout<<0;
	}
	else
				cout<<0;
	return 0;
}