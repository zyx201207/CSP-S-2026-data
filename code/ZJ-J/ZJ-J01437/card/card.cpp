#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+8;
const int MAXM=3e5+8;
int n,m,a[MAXN];
int ans[MAXM],stk[MAXN],tp;
bool in[MAXM];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			memset(in,false,sizeof(in));
			tp=0;
			for(int j=i;j<=n;j++)
			{
				if(in[a[j]]) while(stk[tp]!=a[j]&&tp>0) in[stk[tp]]=false,tp--;
				else in[a[j]]=true,stk[++tp]=a[j];
			}
			for(int j=1;j<=tp;j++) ans[stk[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else if(m==1) cout<<1;
	return 0;
}
