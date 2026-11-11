#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int x,y;
	string r,t;
	cin>>x>>r>>y>>t;
	string a=r.substr(0,2);
	string b=t.substr(0,2);
	char twoa=r[2];
	char twob=t[2];
	
	if(x==y)
	{
		cout<<1;
		if(a==b)
		{
			cout<<1;
			if((twob=='C'&&twoa=='D')||(twoa=='C'&&twob=='D'))
			{
				cout<<"00";return 0;
			 } else{
			 	cout<<1;
			 		if(abs(int(twoa)-int(twob))==1)
					{
						cout<<1;
					}
					else{
						cout<<0;return 0;
					}
			 }
		}else{
			cout<<"000";return 0;
		}
	}else
	{
		cout<<"0000";return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
