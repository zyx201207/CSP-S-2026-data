#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
	if (s==s2) 
	{
		cout<<1;
		int n=(s1[0]-'0')*10+s1[1]-'0',m=(s3[0]-'0')*10+s3[1]-'0';
		if (n==m)
		{
			cout<<1;
			char a=s1[2],b=s3[2];
			if (a>='A' && a<='C' && b>='A' && b<='C') 
			{
				cout<<1;
				if (a=='A' && b=='B') cout<<1;
				else if (a=='B' && b=='A') cout<<1;
				else if (a=='B' && b=='C') cout<<1;
				else if (a=='C' && b=='B') cout<<1;
				else cout<<0;
			}
			else if (a>='D' && a<='F' && b>='D' && b<='F') cout<<11;
			else cout<<"00";
		 }
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
