#include<bits/stdc++.h> 
#define int long long
#define endl "\n"
using namespace std;
const int MAXN=5e5;
int a[MAXN];
bool book[MAXN];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		 } 
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		maxn=a[1];
		for(int i=2;i<=m;i++)
		{
			maxn&=a[i];
		} 
	}
	cout<<maxn;
	return 0;
}
