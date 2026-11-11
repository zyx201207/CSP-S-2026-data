#include<bits/stdc++.h>
using namespace std;
int x;
long long c,t;
long long a[10010];
long long n,d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			x=a[j];
		}
		if(n<=9)
		{
			cout<<x/d;
		}
	}
	return 0;
}

