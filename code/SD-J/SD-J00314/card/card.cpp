#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,x;
int a[N];
stack<int> st;
int m[N],ans[300010];
int c=1;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x;
	int z;
	z=x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(x==1)
	{
		cout<<n<<endl;
		return 0;
	}
	while(1)
	{
		memset(m,0,sizeof(m)); 
		if(c==n)
		{
			ans[a[c]]++;
			break;
		}
		for(int i=c;i<=n;i++)
		{
			if(m[a[i]]==0)
			{
				st.push(a[i]);
				m[a[i]]=1;
			}
			else 
			{
				while(st.top()!=a[i])
				{
					st.pop();
				}
			}
		}
		while(st.size()!=0)
		{
			int tmp=st.top();
			st.pop();
			ans[tmp]++;
		}
		c++;
	}
	for(int i=1;i<=z;i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

