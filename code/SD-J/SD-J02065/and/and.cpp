#include<bits/stdc++.h>
#include<cstdio>
long long  a[210000];
bool cmp(int x,int y)
{
	return x>y;
}
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,maxn=0;
	cin >>n >>m;
	for(int i=1;i<=n;i++)
	{
	
		cin >> a[i];
	
	}
	sort(a+1,a+n+1,cmp);
	cout << a[m];
	return 0;
}
