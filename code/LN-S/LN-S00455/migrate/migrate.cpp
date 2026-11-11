#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define lowbit(x) (x)&(-x)
#define pii pair<int,int>
using namespace std;
const int N=2e6+5;;
const int inf=0x3f3f3f3f3f;
int c,t;
int n,d;
int x[N];
int ans;
inline void f()
{
	int k=x[2]-x[1];
	d/=k;
	if(d<=1)cout<<0<<endl;
	else
	{
		cout<<max(0ll,(n-(2*d-1)))<<endl;
	}
	
}
inline void init()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
}
inline void solve()
{
	init();
	//if(c>=15&&c<=18)
		f();
	//else 
		//cout<<0<<endl;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
		solve();
	return 0;
}
