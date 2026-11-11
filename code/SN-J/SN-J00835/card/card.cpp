//SN-J00835 把小煜 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int pos[300010];
stack<int>st;
int num[300010];
void play(int s)
{
	for(int i=s;i<=n;i++)
	{
		if(pos[a[i]]) 
		{
			while(st.size() && st.top()!=a[i]) pos[st.top()]=0,st.pop();
			if(st.size()) st.pop();
		}
		st.push(a[i]);
		pos[a[i]]=i;
	}
	while(st.size()) num[st.top()]++,st.pop();
	for(int i=s;i<=n;i++) pos[a[i]]=0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) play(i);
	for(int i=1;i<=m;i++) cout<<num[i]<<" ";
	return 0;
}
