#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=505;
int c,n,m,d,q;
long long w[N],ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) 
	{
		cin>>w[i];
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
