#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int n,m,a[500010],c[300010];
void solve(int id)
{
	int cvr = id;
	stack<int> st;
	bool f[300010] = {};
	int cnt[300010] = {};
	for(int i=id;i<=n;i++) cnt[a[i]]++,st.push(a[i]);
	while(cvr<=n)
	{
		if(cnt[a[cvr]]==0)
		{
			st.push(a[cvr]);
			cnt[a[cvr]]++;
			continue;
		}
		while(1)
		{
			int x = st.top();
			if(x==a[cvr]&&cnt[x]==1) break;
			cnt[x]--;
			st.pop();
		}
		cvr++;
	}
	while(!st.empty())
	{
		c[st.top()]++;
		st.pop();
	}	
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool f = 1;
	cin >> n >> m;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
		f&=(a[i]>=a[i-1]);
	}
	for(int i=1;i<=n;i++) solve(i);
	for(int i=1;i<=m;i++) cout << c[i] << " ";
	return 0;
} 
