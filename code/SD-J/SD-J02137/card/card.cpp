#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<int> t;
vector<ll> ans,a;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	ans.assign(m+5,0);
	a.assign(n+5,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		t.assign(m+5,0);
		stack<int> s;
		for(int j=i;j<=n;j++) 
		{
			if(t[a[j]]==0) 
			{
				s.push(a[j]);
				t[a[j]]++;
			}
			else 
			{
				while(s.top()!=a[j]) 
				{
					t[s.top()]--;
					s.pop();
				}	
			}
		}
		for(int j=1;j<=m;j++) 
		{
			if(t[j]!=0) ans[j]++;
//			cout<<t[j]<<' ';
		 } 
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
 } 

