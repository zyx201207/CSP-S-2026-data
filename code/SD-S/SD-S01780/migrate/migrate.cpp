#include<bits/stdc++.h>
#define int long long
using namespace std;

//inline int read()
//{
//	int x=0,f=1;
//	char c=getchar();
//	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
//	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
//	return x*f;
//}

int c,t;
int n,d;
int x,y;

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		cin>>x>>y;
		int c=(y-x);
		int ans=d/c;
		for(int i=3;i<=n;i++)cin>>x;
		if(ans<2)
		{
			cout<<"0\n";
			continue;
		}
		cout<<n-3<<"\n";
	}
	
	return 0;
}
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
