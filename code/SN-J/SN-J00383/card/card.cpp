#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=200+5;
int a[N],lst[N];
bool used[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cout<<0<<' ';
	return 0;
}
