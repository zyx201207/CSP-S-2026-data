#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],d[500005],maxv;
string s;
bool b[5005];
stack<ll> st;
int main()
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
		maxv=max(maxv,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		while(!st.empty()) st.pop();
		for(int j=i;j<=n;j++)
		{	
			if(b[a[j]])
			{
				while(b[a[j]])
				{
					ll k=st.top();
					b[k]=0;
					st.pop();
				}
			}
			st.push(a[j]);
			b[a[j]]=1;
		}
		for(int j=1;j<=maxv;j++)
		{
			if(b[j]) d[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}