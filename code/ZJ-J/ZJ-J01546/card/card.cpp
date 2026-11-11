#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
stack<int> s,d;
int n,m,r[N],st[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=m;i++)st[i]=0;
		for(int i=k;i<=n;i++)
		{
			int x;
			cin>>x;
			if(st[x]>0)
			{
				while(s.top()!=x)s.pop();
				s.pop();
			}
			s.push(x);
			for(int i=1;i<=m;i++)st[i]=0;
			d=s;
			while(d.size())
			{
				st[d.top()]++;
				d.pop();
			}
			for(int i=1;i<=m;i++)
			{
				if(st[i])r[i]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<r[i]<<" ";
		cout<<endl;
	}
	
	return 0;
}

