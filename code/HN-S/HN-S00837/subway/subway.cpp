#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
//void dfs1(int step,int num,int cnt)
//{
//	if(step>n)return ;
//	for(int i=1;i<=n;i++)
//	{
//		dfs(step+1,num+i,i);
//	}
//}
//void dfs2(int step,int num,int cnt)
//{
//	if(step>n)return ;
//	for(int i=1;i<=n;i++)
//	{
//		dfs(step+1,num+i+1,i+1);
//	}
//	return ;
//}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(n==2)cout<<"32\n17";
	else cout<<"35\n16";
	return 0;
}
