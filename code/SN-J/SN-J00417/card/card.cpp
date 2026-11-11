#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500050;
int n,m,a[MAXN],b[MAXN];
int c[MAXN];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		stack<int>q;
		memset(c,0,sizeof(c));
		//cout<<" e ";
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]>0)
			{
				while(q.top()!=a[j])
				{
					c[q.top()]--;
					q.pop();
					//cout<<" t ";
				}
				//cout<<i<<" "<<j<<" "<<q.top()<<endl;
				q.pop();
				c[a[j]]--;
			}
			c[a[j]]++;
			q.push(a[j]);
		}
		while(q.empty()!=1)
		{
			b[q.top()]++;
			q.pop();
			//cout<<" y ";
		}
	}
	//cout<<endl;
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
