#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cnt1=0,cnt2=0;
	for(int i=0;i<2;i++)
	{
		cnt1+=c1[i]-'0';
		cnt2+=c2[i]-'0';
	}
	if(cnt1!=cnt2) cout<<"0000";
	else
	{
		cout<<"1";
		int pai1=0,pai2=0;
		for(int i=0;i<2;i++)
		{
			pai1+=s1[i]-'0';
			pai2+=s2[i]-'0';
		}
		if(pai1!=pai2) cout<<"000";
		else
		{
			cout<<"1";
			int ce1=0,ce2=0;
			if(s1[2]<='C'&&s1[2]>='A') ce1+=1;
			if(s2[2]<='C'&&s2[2]>='A') ce2+=1;
			if(ce1!=ce2) cout<<"00";
			else
			{
				cout<<"1";
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')) cout<<"1";
				else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
} 
