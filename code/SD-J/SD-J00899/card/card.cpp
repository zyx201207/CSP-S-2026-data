#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n,m;
int a[N];
int k;
int s[N];
bool vis[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	if(m<=2)
	{
		if(a[1]!=a[2])
		{
			cout<<"2"<<" "<<"1";
		}
		else
		{
			cout<<"2";
		}
	}
	return 0;
}

