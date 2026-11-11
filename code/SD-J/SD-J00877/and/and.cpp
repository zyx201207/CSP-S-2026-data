#include<bits/stdc++.h>
using namespace std;
int n,m,a[250000],s[250000][50],d=0,o,s1[50];
void er(int i)
{
	int j=1;
	while(a[i]!=1)
	{
		s[i][j]=a[i]%2;
		j++;
		a[i]/=2;
    }
	s[i][j]=1;	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		d=max(d,a[i]);
	}
	for(int i=1;i<=31;i++)
	{
		if(pow(2,i)>d)
		{
			o=i;
			break;
		} 
	}
	for(int i=1;i<=n;i++)
	{
		er(i);
	}
	for(int i=1;i<=o;i++)
	{
		int y=0;
		for(int j=1;j<=n;j++)
		{
			if(s[j][i]==1) y++;
			if(y==m)
			{
				s1[i]=1;
				break;
			}
		}
	}
	int v=0;
	for(int i=1;i<=o;i++)
	{
		v+=(2,i)*s1[i];
	}
	cout<<v;
	return 0;
}
