#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("teavel.in","r",stdin);
    freopen("teavel.out","w",stdout);
    int c1,s1,c2,s2;
    cin>>c1>>c2>>s1>>s2;

    int a=0,b=0,c=0,d=0;
    if(c1==s1)
    {
        a==1;
        if(s2==c2)
        {
            b==1;
            if(c2-s2==1)
            {
            	c==1;
            	if(c2-s2==1)
            	{
            		d==1;
            	}
            }
        }
        else
        {
            b==0;
        }
    }
    else
    {
        a==0;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
