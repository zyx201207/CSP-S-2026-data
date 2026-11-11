#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}