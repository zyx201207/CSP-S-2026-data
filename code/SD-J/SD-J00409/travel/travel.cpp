#include<bits/stdc++.h>
using namespace std;
int w_c1,w_c2;
string w_s1,w_s2;
int w_p1,w_p2;
int w_d1,w_d2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>w_c1>>w_s1>>w_c2>>w_s2;
	w_p1=(w_s1[0]-'0')*10+w_s1[1]-'0';
	w_p2=(w_s2[0]-'0')*10+w_s2[1]-'0';
	if(w_s1[2]=='D'||w_s1[2]=='F')
	{
		w_d1=2;
	}
	else
	{
		w_d1=1;
	}
	if(w_s2[2]=='D'||w_s2[2]=='F')
	{
		w_d2=2;
	}
	else
	{
		w_d2=1;
	}
	if(w_c1==w_c2)
	{
		cout<<1;
		if(w_p1==w_p2)
		{
			cout<<1;
			if(w_d1==w_d2)
			{
				cout<<1;
				if(abs((w_s1[2]-'A')-(w_s2[2]-'A'))==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
