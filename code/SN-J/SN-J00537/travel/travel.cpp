#include<bits/stdc++.h>
using namespace std;
char sa[5],sc[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int t=s1.size();
	for(int i=0;i<t;i++)
	{
		sa[i]=s1[i];
		
	
	}
	int t1=s2.size();
	for(int i=0;i<t1;i++)
	{
		sc[i]=s2[i];
	}
	int q=sc[2]-sa[2];
	if(c1==c2)
	{
		cout<<1;
		if(sa[0]==sc[0]&&sa[1]==sc[1])
		{
			 cout<<1;
			if(((sa[2]=='A'||sa[2]=='B'||sa[2]=='C')&&(sc[2]=='A'||sc[2]=='B'||sc[3]=='C'))||((sa[2]=='D'||sa[2]=='F')&&(sc[2]=='D'||sc[2]=='F')))
			 {
			 	cout<<1;
			 	if((sa[2]>='A'&&sa[2]<='c'&&abs(q)==1)||(sa[2]>='D'&&sa[2]<='F'&&abs(q)==2))
			 	{
			 		cout<<1;
				}
				 else
				 cout<<"0";
			 }
			 else
			 {
			 	cout<<"00";
			 }
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
