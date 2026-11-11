#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
stack<int> st;
int lst[M],n,m,a[N],ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
			flag=0;
	}
	if(flag && n>5000)
	{
		for(int i=1;i<=n;i++)
			lst[a[i]]=i;
		for(int i=1;i<=m;i++)
			cout<<lst[i]<<' ';
		return 0;
	}
	for(int len=1;len<=n;len++)
	{
		memset(lst,-1,sizeof lst);
		for(int i=len;i<=n;i++)
		{
			if(lst[a[i]]==-1)
			{
				st.push(i);
				lst[a[i]]=i;
				continue;
			}
			int tmp=lst[a[i]];
			while(!st.empty() && st.top()!=tmp)
			{
				lst[a[st.top()]]=-1;
				st.pop();
			}
			//st.push(i);
		}
		for(int i=1;i<=m;i++)
			if(lst[i]!=-1)
				ans[i]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
}
