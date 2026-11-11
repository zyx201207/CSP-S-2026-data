#include<bits/stdc++.h>
using namespace std;
int a[500005];
int z[500005];
int b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,k,l;
	string t="",s,y;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		t="";
		int z[500005]={0};
		for(j=i;j<=n;j++)
		{	
			s="";
			if(t.find(char(a[j]+'0'))!=-1&&j!=i)
			{
				for(k=0;k<z[a[j]];k++)
				{
					s+=t[k];
				}
				for(k=z[a[j]];k<t.size();k++)
				{
					z[t[k]-'0']=0;
				}
				t=s;
			}
			else
			{
				z[a[j]]=t.size()+1;
				t+=char(a[j]+'0');
			}
			
		}
		l=t.size();
		for(j=0;j<l;j++)
		{
			b[t[j]-'0']++;
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
