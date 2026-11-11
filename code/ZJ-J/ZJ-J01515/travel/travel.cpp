#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		int x=0,y=0,l1=b.size(),l2=d.size();
		for(int i=0;i<l1-1;i++)
		{
			x*=10;
			x+=b[i]-'0';
		}
		for(int i=0;i<l2-1;i++)
		{
			y*=10;
			y+=d[i]-'0';
		}
//		cout<<x<<" "<<y;
		if(x==y)
		{
			int n=b[l1-1]-'A',m=d[l2-1]-'A';
			if(n==0&&m==3||n==1&&m==3||n==2&&m==3||n==0&&m==4||n==1&&m==4||n==2&&m==4) cout<<"1100";
			else
			{
				swap(n,m);
				if(n==0&&m==3||n==1&&m==3||n==2&&m==3||n==0&&m==4||n==1&&m==4||n==2&&m==4) cout<<"1100";
				else
				{
					if(abs(n-m)==1) cout<<"1111";
					else cout<<"1110";
				}
			}
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
