#include<bits/stdc++.h>
using namespace std;
string a1,b1;
int main()
{
	freeopen("travel.in","r",stdin);
	freeopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	char a=s2[2];
	char b=s4[2];
	if(a>b) swap(a,b);//×ÖÄ¸ 
    a1+=s2[0];
    a1+=s2[1];
	b1+=s4[0];
	b1+=s4[1];//Êý×Ö 
	if(s1==s3)
	{
		cout<<1;
		if(a1==b1) 
		{
			cout<<1;
			if(!((a=='A'||a=='B'||a=='C')&&(b=='D'||b=='F')))
			{
				cout<<1;
				if((b-a)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
