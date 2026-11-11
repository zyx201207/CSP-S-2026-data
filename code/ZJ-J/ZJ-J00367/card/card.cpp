#include<bits/stdc++.h>
using namespace std;
int n,m,v[300010],a[500010],b[300010];
//rp++
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int K=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			K=1;
		}
	}
	if(n<=500)
	{
		
		stack<int>st;
		for(int i=1;i<=n;i++)
		{
			
			for(int j=i;j<=n;j++)
			{
				
				if(v[a[j]]==0)
				{
					st.push(a[j]);
					v[a[j]]=1;
				}	
				else
				{
					while(st.top()!=a[j])
					{
						v[st.top()]--;
						st.pop();
					}
				}
			}	
			for(int j=1;j<=m;j++)
			{
				if(v[j]>=1)
				{
					b[j]++;
				}
				v[j]=0;
			}
			while(st.size()!=0)
			{
				st.pop();
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<b[i]<<' ';
		}
		return 0;
	}
	else
	{
		if(K==0)
		{
			for(int i=1;i<=n;i++)
			{
				b[a[i]]=max(i,b[a[i]]);
			}
			
		}
		for(int i=1;i<=m;i++)
		{
			cout<<b[i]<<' ';
		}
	}
	return 0;
}