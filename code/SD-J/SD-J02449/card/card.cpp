#include<bits/stdc++.h>
using namespace std;
string s;
int a[700000];
int c[700000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int w,q;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int j=1;j<=n;j++)
	{
		string s;
		for(int i=j;i<=n;i++)
		{
			char b=char(c[i]+48);
			q=int(s.find(b));
			if(q==-1)
			{
				s+=b;
			}
			else if(q!=-1)
			{
				w=s.size()-1;
				s.erase(q,w+1);
				s+=b;
			}
		}
		for(int t=1;t<=m;t++)
		{
			char r=char(t+48);
			if(int(s.find(r))!=-1)
			{
				a[t]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
