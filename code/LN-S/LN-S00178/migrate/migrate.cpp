#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)
	{
		int n;long long d;cin>>n;cin>>d;
		for(int i=0;i<n;i++)	cin>>a[i];
		long long k=a[1]-a[0];
		if(k==0 || d<2*k) cout<<"0";
		else {int ans=n-(2*(d/k))+1;cout<<max(0,ans);}
		cout<<endl;
	}
	return 0;
}
