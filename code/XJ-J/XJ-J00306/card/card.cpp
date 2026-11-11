#include <bits/stdc++.h> 
using namespace std;
int n,m;
int a[500005];
bool vis[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[a[i]]=1;
	}
	cout<<n<<" "<<m<<" "<<a[1];
	return 0;
}
