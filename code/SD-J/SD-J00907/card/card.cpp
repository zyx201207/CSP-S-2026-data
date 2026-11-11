#include <bits/stdc++.h>
#define CHECK_SIZE(x) cout<<#x<<": "<<sizeof(x)%1024<<"B "<<sizeof(x)%(1024*1024)/1024<<"KB "<<sizeof(x)/1024/1024<<"MB\n"
using namespace std;
const int N=5e5+7;
const int M=2e5+7;
int n,m;
int a[N],ans[M];
int stk[N],t;
bool in_stk[M];
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=i;j<=n;j++)
		{
			if(in_stk[a[j]])
			{
				int u;
				do{
					u=stk[t];
					in_stk[u]=false;
					t--;
				}while(u!=a[j]);
			}
			stk[++t]=a[j];
			in_stk[a[j]]=true;
		}			
		while(t)
		{
			ans[stk[t]]++;
			in_stk[stk[t]]=false;
			t--;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" \n"[i==m];	
}
void solve2()
{
	for(int i=1;i<=n;i++)
		ans[a[i]]=i;
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" \n"[i==m];
}
void check_size()
{
	CHECK_SIZE(a);
	CHECK_SIZE(ans);
	CHECK_SIZE(stk);
	CHECK_SIZE(in_stk);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
//	check_size();
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	if(n<=5000)
		solve1();
	else
		solve2();
	return 0;
} 
