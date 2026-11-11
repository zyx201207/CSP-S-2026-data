#include<bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		long long n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			long long x;
			cin>>x;
		}
		cout<<n*(n-1)/2-n+1<<endl;
	}
	return 0;
} 
