#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
	int c1,c2;
	string s1,s2;
	
	cin>>c1>>s1>>c2>>s2;
	int as=(int)s1[1]-'0'+(int)s1[0]-'0'*10,bs=(int)s2[1]-'0'+(int)s2[0]-'0'*10;
	int ay=(int)s1[2]-'A',by=(int)s2[2]-'A';
	
	if(c1==c2) {
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	if(c1==c2&&as==bs)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	
	if((c1==c2&&as==bs)&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	
	if(c1==c2)
	{
		for(int i=0;i<4;i++)
		{
			if(as+dx[i]==bs&&ay+dy[i]==by&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))
			{
				cout<<"1";
				return 0;
			}
		}
	}
	cout<<"0";
	return 0;
}

