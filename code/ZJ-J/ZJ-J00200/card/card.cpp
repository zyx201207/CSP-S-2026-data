#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m;
const int N=5e5+10;
LL a[N];
LL c[N];
bool b=0;
stack<LL>st;
LL sum[N];
LL s[N];
LL su[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			b=1;
		}
	}
	if(!b)
	{
		for(LL i=1;i<=n;i++)
		{
			su[a[i]]++;
		}
		for(LL i=1;i<=m;i++)
		{
			int j=i-1;
			while(su[i]==0)i++;
			su[i]+=su[j]+i-j-1;
		}
		for(LL i=1;i<=m;i++)
		{
			cout<<su[i]<<' ';
		}
		return 0;
	}
	for(LL i=1;i<=n;i++)
	{
		while(st.size())
		{
			st.pop();
		}
		for(LL i=1;i<=m;i++)
		{
			s[i]=0;
		}
		for(LL j=i;j<=n;j++)
		{
			if(s[a[j]])
			{
				while(st.top()!=a[j])
				{
					s[st.top()]--;
					st.pop();
				}
			}
			else
			{
				s[a[j]]++;
				st.push(a[j]);
			}
		}
		for(LL j=1;j<=m;j++)
		{
			sum[j]+=s[j];
		}
	}
	for(LL i=1;i<=m;i++)
	{
		cout<<sum[i]<<' ';
	}
}
