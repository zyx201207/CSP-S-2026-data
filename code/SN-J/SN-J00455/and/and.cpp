#include<bits/stdc++.h>
using namespace std;
//SN-J00455 zhaoweize

int n,m;
int a[200005];
int ans;
bool cmp(int &a,int &b)
{	
	if(__builtin_popcount(a)==__builtin_popcount(b))return a>b;
	return __builtin_popcount(a)>__builtin_popcount(b);
}
int main()
{	
	ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=1;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
