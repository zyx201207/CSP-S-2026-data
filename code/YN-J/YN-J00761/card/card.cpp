#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
int a[maxn];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> b(m+5);
	bool sp=1;//判断特殊性质A
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(sp&&(a[i]-a[i-1])!=1) sp=0;
		
	} 
	if(sp)
	{
		for(int i=m;i>=1;--i) cout<<m<<' ';
	}else
	{
		for(int i=1;i<=n;++i)
		{
			vector<bool> f(m+5);
			queue<int> q;
			for(int j=i;j<=n;++j)
			{
				if(f[a[j]]) 
				{
					while(q.front()!=a[j])
					{
						f[q.front()]=0;
						q.pop(); 
					}
				}
				else
				{
					q.push(a[j]);
					f[a[j]]=1;
				}
			}	
			while(!q.empty())
			{
				b[q.front()]++;
				q.pop();	
			}
		}
		for(int i=1;i<=m;++i) cout<<b[i]<<' ';
	}
	return 0;
}
//dp?贪心?,难度:普及+/提高-
//特殊A+随便骗了点
//预估:4