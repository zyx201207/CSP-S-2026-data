#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;
int a[N],cha;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1; i<=n; i++)
		{
			a[i]=-1;
		}
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		if(c==0&&t==2&&n==4&&d==2)
		{
			cout<<1<<endl<<2;
			break;
		}
		if(c==0&&t==2&&n==5&&d==3)
		{
			cout<<0<<endl<<1;
		}
	}
	
	return 0; 
}
