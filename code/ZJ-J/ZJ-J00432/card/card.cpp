#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
stack<int>s;
bool vit[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(!vit[a[j]])
			{
				s.push(a[j]);
				vit[a[j]]=1;
			}
			else
			{
				while(s.top()!=a[j])
				{
					vit[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			b[s.top()]++;
			vit[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;++i)
	{
		cout<<b[i]<<' ';
	}
	return 0;
	fclose(stdin);
	fclose(stdout);	
}
