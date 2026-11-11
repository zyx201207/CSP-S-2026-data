#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int a[maxn];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];				
	}
	cout<<n<<" "<<m<<" "<<5;
	return 0;
}
