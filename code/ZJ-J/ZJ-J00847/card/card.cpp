#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],f[M],ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		stack<int> st;
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				st.push(a[j]);
				f[a[j]]=1;
			}
			else
			{
				while(f[a[j]])
				{
					int t=st.top();
					st.pop();
					f[t]=0;
				}  
				st.push(a[j]);
				f[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(f[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}