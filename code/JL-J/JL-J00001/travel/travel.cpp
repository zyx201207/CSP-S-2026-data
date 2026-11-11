#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int num1,num2;
	string sR,sX;
	cin>>num1>>sR>>num2>>sX;
	if(num1==num2)
	{
		cout<<1;
		if(sR[0]==sX[0]&&sR[1]==sX[1])
		{
			cout<<1;
			if((sR[2]<='C'&&sX[2]<='C')||(sR[2]>='D'&&sX[2]>='D'))
			{
				cout<<1;
				if(min(sR[2],sX[2])+1==max(sR[2],sX[2]))
					cout<<1;
				else 
				{
					if(min(sR[2],sX[2])=='D'&&max(sR[2],sX[2])=='F')
						cout<<1;
					else 
						cout<<0;
				}
			}
			else 
				cout<<"00";
		}
		else 
			cout<<"000";
	}
	else cout<<"0000";
	
	cout<<'\n';
	return 0;
}
