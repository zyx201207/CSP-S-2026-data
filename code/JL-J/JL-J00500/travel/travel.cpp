#include <bits/stdc++.h>
using namespace std;
int seat[10][5];
char a1[3],a2[3];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2;
	    if(a1[0]!=a2[0]||a1[1]!=a2[1])
	    {
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<1;
		}

	    return 0;
}
