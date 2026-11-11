#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2;
	bool bz=0,bz2=0,bz3=0;
	string b1,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)
	{
		cout<<"1";
	}
	else{
		cout<<"0";
		bz3=1;
	}
	if(bz3==1)
	{
		cout<<"0";
		bz=1;
	}
	else{
		for(int i=0;i<2;i++)
		{
			if(b1[i]!=b2[i])
			{
				cout<<"0";
				bz=1;
				break;
			}
		}
	}
	if(bz==0)
	{
		cout<<"1";
	}
	if(bz==1)
	{
		cout<<"0";
		bz2=1;
	}
	else{
		if(((b1[2]>='A' && b1[2]<='C') && (b2[2]>='A' && b2[2]<='C')) || ((b1[2]=='D' && b1[2]=='F') && (b2[2]=='D' && b2[2]=='F')))
		{
			cout<<"1";
		}
		else{
			cout<<"0";
			bz2=1;
		}
	}
	if(bz2==1)
	{
		cout<<"0";
	}
	else{
		if((b1[2]=='A' && b2[2]=='B') || (b1[2]=='B' && b2[2]=='A') || (b1[2]=='B' && b2[2]=='C') || (b1[2]=='C' && b2[2]=='B') || (b1[2]=='D' && b2[2]=='F') || (b1[2]=='F' && b2[2]=='D'))
		{
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
}
