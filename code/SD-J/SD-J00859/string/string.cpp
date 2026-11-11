#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int a,h=0,m=0,g=0,l;
	string t;
	cin>>a;
	long long int b[a],j;
	char d[a];
	for(int i=0;i<a;i++)
	{
		cin>>b[i]>>d[i];
		m+=b[i];
	}
	if(m>100000)
	{
		j=a-1;
		int x=0;
		m=m/2;
		for(x=0;m>0;x++)
		{
			m-=b[x];
		}
		for(int i=0;g<x+1;i++)
		{
			if(d[g]!=d[j])
			{
				if(b[g]>b[j])
				{
					b[g]-=b[j];
					h+=b[j];
					b[j]=0;
					j--;
				}
				else if(b[g]==b[j])
				{
					b[g],b[j]=0;
					h+=b[g];
					g++;
					j--;
				}
				else
				{
					b[j]-=b[g];
					b[g]=0;
					g++;
					h+=b[g];
				}
			}
		}
		cout<<h;
	}
	else
	{
		for(int i=0;i<a;i++)
		{
			for(j=0;j<b[i];j++)
			{
				t+=d[i];
			}
		}
		string x;
		x=t;
		h=0;
		for(j=0;j<t.length();j++)
		{
			if(t[j]!=t[t.length()-j-1])
			{
				t[t.length()-j-1]=t[j];
				h++;
			}
		}
		l=h;
		h=0;
		t=x;
		for(j=0;j<t.length();j++)
		{
			if(t[j]!=t[t.length()-j-1])
			{
				t[j]=t[t.length()-j-1];
				h++;
			}
		}
		if(h<l)
		{
			l=h;
		}
		cout<<l;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
