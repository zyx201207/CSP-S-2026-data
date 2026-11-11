#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n,m;
ull maxn=0;
ull a[200001];
bool cmp(ull a,ull b){return a<b;}
ull f(int in,int hei)
{
	if(hei==m) return a[in];
	ull t = (a[in]&f(in+1,hei+1));
	for(int i = in+2;i <= n;i++)
	{
		t=max(t,(t&f(i,hei+1)));
	}
	return t;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n-m+1;i++) maxn=max(maxn,f(i,1));
	cout << maxn;
	return 0;
}
