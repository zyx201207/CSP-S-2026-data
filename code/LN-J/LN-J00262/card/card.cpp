#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
int a[N],b[N];
bool f[N];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		f[i]=true;
	}
	cout<<n<<' '<<m<<7;
	return 0;
}
