#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,t,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>t;
	if(1)
	{
		while(t--){
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
			}
			cout<<n*(n-1)/2<<endl;
		}
	}
	return 0;
}