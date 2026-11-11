#include<bits/stdc++.h>
using namespace std;
int che1,che2,a,b;
string zuoa,zuob,piaa,piab;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>zuoa>>che2>>zuob;
	if(che1==che2)
	{
		cout<<"1";
		if(zuoa[0]==zuob[0]&&zuoa[1]==zuob[1])
		{
			cout<<"1";
			if(((zuoa[2]=='A'||zuoa[2]=='B'||zuoa[2]=='C')&&(zuob[2]=='A'||zuob[2]=='B'||zuob[2]=='C'))||((zuoa[2]=='D'||zuoa[2]=='F')&&(zuob[2]=='D'||zuob[2]=='F')))
			{
				cout<<"1";
				if((zuoa[2]=='C'&&zuob[2]=='A')||(zuoa[2]=='A'&&zuob[2]=='C'))
				{
					cout<<"0";
				}
				else
				{
					cout<<"1";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
