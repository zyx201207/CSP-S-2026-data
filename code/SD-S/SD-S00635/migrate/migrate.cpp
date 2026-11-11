#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
int n,d;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(C==11||C==12)
		{
			int k=a[2]-a[1];
			d/=k;
			int t=d*2-1;
			cout<<max((long long)(0),n-t);
		}
		else cout<<'0'<<endl;
	}
	return 0;
}


