#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char chexiang1[5];
	char chexiang2[5];
	char seat1[6];
	char seat2[6]; 
	cin>>chexiang1>>seat1>>chexiang2>>seat2;
	for(int i=0;i<2;i++)
	{
		if(chexiang1[i]!=chexiang2[i]){
			cout<<chexiang1[i]<<'.'<<chexiang2[i]<<'.';
			cout<<"0000";
			return 0;
		}
	}
	if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]){
		if(seat1[2]<=67&&seat2[2]<=67||seat1[2]>67&&seat2[2]>67)
		{
			if(seat1[2]=='A'&&seat2[2]=='B'||seat1[2]=='B'&&seat2[2]=='A'||seat1[2]=='C'&&seat2[2]=='B'||seat1[2]=='B'&&seat2[2]=='C'||seat1[2]=='D'&&seat2[2]=='F'||seat1[2]=='F'&&seat2[2]=='D')
			{
				cout<<"1111";
			}else{
				cout<<"1110";
			}
		}else{
			cout<<"1100";
		}
	}else{
		cout<<"1000";
	}
	return 0;
}
