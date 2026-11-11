#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1])
		{
			cout<<1;
			if(s1[2]<='C' and s2[2]<='C'){
				cout<<1;
				if(s1[2]=='B' or s2[2]=='B')
					cout<<1;
				else
					cout<<0;
			}
			else if(s1[2]>'C' and s2[2]>'C')
				cout<<1<<1;
			else
				cout<<0<<0;
		}
		else
			cout<<0<<0<<0;
	}else{
		cout<<0<<0<<0<<0;
	}
}
