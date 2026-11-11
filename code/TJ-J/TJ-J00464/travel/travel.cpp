#include<bits/stdc++.h>;
using namespace std;
string a,b,c,d,a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool x=0,y=0,n=0,m=0;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		x=1;
		if(b[0]==d[0] && b[1]==d[1])
		{
			y=1;
		}
		if(y==1)
		{
			if((('A'<=b[2]<='F') && ('A'<=d[2]<='F')))
			{
				n=1;
			}
			if((b[2]=='C'&&d[2]=='D') or (b[2]=='D'&&d[2]=='C'))
			{
				n=0;
			}
			if(n==1)
			{
				if((b[2]+1==d[2]) || (b[2]==d[2]))
				{
					m=1;
				}
			}
		}
	}
	cout<<x<<y<<n<<m;
}
