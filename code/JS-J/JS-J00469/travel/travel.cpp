#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
//A touch woke a silent storm
//A sign a broken cry
//Every tear ran down your face
//Eched a Goodbye
//A passing glance,so close yet strange
//Was a vow ever made
//Drowling in the wheels of fate
//Can't evade
//Wuu~ Wuu~ WuWu
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)
	{
		cout<<1;
		if(c2[0]==s2[0]&&c2[1]==s2[1])
		{
			cout<<1;
			if(c2[2]>s2[2])swap(c2,s2);
			if(c2[2]=='D'&&s2[2]=='F'||c2[2]=='A'&&s2[2]=='C'||c2[2]=='A'&&s2[2]=='B'||c2[2]=='B'&&s2[2]=='C')
			{
				cout<<1;
				if(c2[2]=='D'&&s2[2]=='F'||c2[2]=='A'&&s2[2]=='B'||c2[2]=='B'&&s2[2]=='C')
					cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
