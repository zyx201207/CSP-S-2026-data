#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int T,n,m,x[N],y[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>T>>T;
	while (T--)
	{
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i];
		}
		cout<<(m+1)/2<<"\n";
	}
	return 0;
}
