#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		b[i]=0;
	}
	for(int j=0;j<n;j++)
	{
		string k;
		for(int i=0;i<n;i++)
		{
			k+='0';
		}
		int h=0;
		for(int i=j;i<n;i++)
		{
			int t=0;
			for(int o=0;o<h;o++)
			{
				if(k[o]==char(a[i]+'0'))
				{
					h=o+1;
					t++;
					break;
				}
			}
			if(!t)
			{
				k[h]=char(a[i]+int('0'));
				h++;
			}
		}
		for(int i=0;i<h;i++)
		{
			b[int(k[i]-'0')-1]++;
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
