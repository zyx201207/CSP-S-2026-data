#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[500005],b[300005],app[300005],turn=1;
int ans[300005];
int stk[500005],top;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]!=turn)
			{
				b[a[j]]=turn;
				stk[++top]=a[j];
				app[a[j]]=top;
			}
			else
			{
				top=app[a[j]];
				//~ app[a[j]]=top;
				++turn;
				for(int k=1;k<=top;k++) b[stk[k]]=turn;
			}
			
			//~ for(int j=1;j<=top;j++)
			//~ {
				//~ cout<<stk[j]<<" ";
			//~ }
			//~ cout<<endl;
		}
		for(int j=1;j<=top;j++) ans[stk[j]]++;
		
		//~ for(int j=1;j<=top;j++)
		//~ {
			//~ cout<<stk[j]<<" ";
		//~ }
		//~ cout<<endl;
		
		memset(b,0,sizeof b);
		turn=1;
		top=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
