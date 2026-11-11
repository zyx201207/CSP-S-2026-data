#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
int a[500100];
int ans[500100];
map<int,queue<int>> mi;
int cfa[500100];
int rans[500100];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=i;
//		cfa[i]=ans[i]-ans[i-1];
		mi[a[i]].push(i);
	}
	for(int i=1;i<=m;i++)
	{
		int start=0,end=0;
		while(mi[i].size()>1)
		{
			if(start==0&&end==0)
			{
				start=mi[i].front();
				mi[i].pop();
				end=mi[i].front();
			}
			else
			{
				start=end;
				mi[i].pop();
				end=mi[i].front();	
			}	
//			cfa[end]+=start;
//			cfa[start]-=start;
			for(int j=start+1;j<end;j++)
			{
				ans[j]-=ans[start];
			}
			ans[start]-=ans[start];
		}
		
	}
	
	for(int i=1;i<=n;i++)
	{
		rans[a[i]]+=ans[i];
	}
	for(int i=1;i<=m;i++)cout<<rans[i]<<" ";
	return 0;
}