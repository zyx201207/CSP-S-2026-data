#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin>>c1,s1,c2,s2;
    int b;
    for(int i=1;i<=c1.size();i++)
    {
    	if(c1==c2)
    	{
    		cout<<"1";
    		b==0;
		}
		else
		{
			cout<<"0";
		}
		if(b==0)
        {
            cout<<"111";
        }
        else
        {
            cout<<"000";        }

	}
    return 0;
}
