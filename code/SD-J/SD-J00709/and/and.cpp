#include<bits/stdc++.h>
using namespace std;

int n,m;

struct Node{
	int num;
//	bool x[40]={0};
}a[200010];

bool cmp(Node A,Node B)
{
	return A.num>B.num;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	int c;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		a[i].num=c;
//		int now=1;
//		while(c>0)
//		{
//			a[i].x[now++]=c&1;
//			c>>=1;
//		}
	}
	sort(a+1,a+n+1,cmp);
	
	int ans=2147483647;
	for(int i=1;i<=m;i++)
	{
		ans&=a[i].num;
	}
	
	cout<<ans;
	return 0;
}

