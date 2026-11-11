#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int m,n,q=4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]=='F'){
		m=5;
	}
	else if(d[2]=='F'){
		n=5;
	}
	else
	{
		m=b[2]-'A'+1;
		n=d[2]-'A'+1;
	}
	if(a==c)
	{
		cout<<"1";
		q--;
		if(b[0]==d[0] && b[1]==d[1])
		{
			cout<<"1";
			q--;
			if((m<=3 && n<=3) || (m>3 && n>3))
			{
				cout<<"1";
				q--;
				if(m-n==1 || n-m==1)
				{
					cout<<"1";
					q--;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<"0";
	}
	return 0;
}
