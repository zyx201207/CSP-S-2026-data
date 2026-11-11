#include<bits/stdc++.h>
using namespace std;

struct people
{
	string train;
	int number;
	char A;
}a,b;

string c1,s1,c2,s2;
bool z[5]={0};
string c={'A','B','C','D','F'};
string char_1={'A','B','C'};
string char_2={"DF"};
string f[6]={"AB","BC","DF","BA","CB","FD"};
string cmp;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a.train=c1;
	b.train=c2;
	for(int i=0;i<=1;i++)
	{
		a.number+=s1[i];
		b.number+=s1[i];
	}
	a.A=s1[2];
	b.A=s2[2];
	if(a.train==b.train)
	{
		z[1]=true;
	}
	else
	{
		for(int i=1;i<=4;i++)
		{
			cout<<z[i];
		}
		return 0;
	}
	cmp+=s1[2];
	cmp+=s2[2];
	if(a.number==b.number)
	{
		z[2]=true;
		if(char_1.find(s1[2])!=string::npos && char_1.find(s2[2])!=string::npos || char_2.find(s1[2])!=string::npos && char_2.find(s2[2])!=string::npos)
		{
			z[3]=true;
			for(int i=0;i<6;i++)
			{
				if(f[i]==cmp)
				{
					z[4]=true;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<z[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
