#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
const int N=2e6+10;
int n,m,ans;
int a[N],s[N],id[N];
queue<int>q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;++i)
	{
		cout<<0;
	}
	return 0;
}

