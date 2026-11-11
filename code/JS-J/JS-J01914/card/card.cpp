#include<bits/stdc++.h>
using namespace std;

int n,m;
int ans[500001];
int a[500001];
int sz=0,stk[500001];
bool ison[500001];

int lst[500001],bfr[500001];

inline void p()
{
	for(int i=1;i<=n;i++)
	{
		sz=0;
		for(int j=i;j<=n;j++)
		{
			stk[++sz]=a[j];
			if(!ison[a[j]])
			{
				ison[a[j]]=1;
			}
			else
			{
				sz--;
				while(stk[sz]!=a[j])
				{
					ison[stk[sz]]=0;
					sz--;
				}
			}
		}
		for(int j=1;j<=sz;j++)
		{
			ans[stk[j]]++;
			ison[stk[j]]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5000&&m<=3000)
	{
		p();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(lst[a[i]]!=0)
		{
			bfr[i]=lst[a[i]];
		}
		lst[a[i]]=i;
	}
	sz=0;
	for(int i=n;i>=1;i--)
	{
		stk[++sz]=a[i];
		if(!ison[a[i]])
		{
			ison[a[i]]=1;
		}
		else
		{
			sz--;
			while(stk[sz]!=a[i])
			{
				ison[stk[sz]]=0;
				sz--;
			}
		}
		for(int j=1;j<=sz;j++)
		{
			ans[stk[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	
	//er fen
	
	for(int col=1;col<=m;col++)
	{
		
	}
	return 0;
}
