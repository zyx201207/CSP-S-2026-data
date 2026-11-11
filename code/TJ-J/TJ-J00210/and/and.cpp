#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
	int num,c1;
	string _01;
	void Dtom()
	{
		int n = num;
		while(n!=0)
		{
			_01 = char(n%2+'0')+_01;
			c1+=n&2;
			n/=2;
		}
	}
}a[200010];
priority_queue<int> q;
bool cmp(node x,node y)
{
	if(x.c1!=y.c1) return x.c1>y.c1;
	if(x._01.size()!=y._01.size()) return x._01.size()>y._01.size();
	for(int i=0;i<x._01.size();i++)
	{
		if(x._01[i]!=y._01[i]&&x._01[i]=='1')
		{
			if(x._01[i]=='0') return 0;
			else return 1;
		}
	}
	return 0;
}
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i].num;
	for(int i=1;i<=n;i++) a[i].Dtom();
	sort(a+1,a+n+1,cmp);
	int ans = a[1].num;
	for(int i=1;i<=m;i++) ans&=a[i].num;
	cout << ans << endl;
	return 0;
} 
