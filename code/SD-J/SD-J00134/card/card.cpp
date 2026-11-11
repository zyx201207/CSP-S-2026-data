#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int P=998244353;
const long long INF=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10,M=2e6+10;

int n,m;
int a[N+N],x[N];
int id[N],ans[N];
bool b[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	fst
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		int len=0;
		for(int j=i;j<=n;j++)
	    {
	    	if(b[x[j]])
		    {
		    	for(int k=id[x[j]]+1;k<=len;k++)
		    	{
		    		b[a[k]]=0;
				}
			    len=id[x[j]];
		    }
	    	else
		    {
		    	a[++len]=x[j];
		    	id[x[j]]=len;
		    }
		    b[x[j]]=1;
	    }
	    for(int j=1;j<=len;j++)
		{
		    ans[a[j]]++;
	    }
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

