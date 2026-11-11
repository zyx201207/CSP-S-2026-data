#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	string x=b.substr(0,2);
	string y=d.substr(0,2);
	char p=b[2];
	char q=d[2];
	if(a==c)
	{
		cout<<1;
		if(x==y)
		{
			cout<<1; 
			int ok=1;
			if(('D'==p||p=='E')&&('D'==q&&q=='E')&&ok)
			{
				cout<<"11"<<endl;
				return 0;
			}
			if((p=='A'||p=='C'||p=='B')&&(q=='A'||q=='C'||q=='B'))
			{
				ok=0;
				cout<<1;
				if(abs(p-q)==1)
				{
					cout<<1<<endl;
					return 0;
				}
				else
				{
					cout<<0<<endl;
					return 0;
				}
			}
			else{
				cout<<"00"<<endl;
				return 0;
			}
		}
		else{
			cout<<"000"<<endl;
			return 0;
		}
	
	}
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	return 0;	
} 
