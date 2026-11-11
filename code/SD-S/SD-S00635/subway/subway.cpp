#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int w[M];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		string s;
		getline(cin,s);
	}
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		printf("%lld",w[a]+w[b]+2);
	}
	return 0;
}


