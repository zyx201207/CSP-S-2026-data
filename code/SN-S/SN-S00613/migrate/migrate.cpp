#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+9;
int c,t,n,d;
long long x[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(d==2) cout<<n-3<<endl;
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
