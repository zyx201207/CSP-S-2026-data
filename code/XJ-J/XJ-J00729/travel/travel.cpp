#include<bits/stdc++.h>
using namespace std;
long long int i,a1,a2,a3,a4,c[10],d[10];
char a[10],b[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(i=1;i<=2;i++)
	{
		
		cin>>d[i]>>a[i]>>c[i]>>b[i];
    }
		if(d[1]==d[2])
		{
			cout<<"1";
			if(c[1]==c[2])
			{
			cout<<"1";
			if(b[1]-1+1<='D'-1+1&&b[2]-1+1<='D'-1+1||b[1]-1+1>'D'-1+1&&b[2]-1>'D'-1+1)
			{
				cout<<"1";
				if(b[1]-1+1==b[2]-1)
            {
            	cout<<"1";
            	return 0;
			}
			else
			cout<<"0";
			}
			else
			cout<<"0";
			}
			else
			{
			cout<<"0";
			}
		}
		else
		cout<<"0";
		
		return 0;
} 
