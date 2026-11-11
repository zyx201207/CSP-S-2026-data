#include <bits/stdc++.h>
using namespace std;
int a[2000001];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,i,k,p,m;
	cin>>c>>t;
	while(t--)
	{
		int sum=0;
		cin>>n>>d;
		for(i=1;i<=n;i++)
			cin>>a[i];
		k=a[2]-a[1];
		p=d/k;
		if(p==1)
			cout<<0<<endl;
		m=(a[n]+p-1)/p;
		for(i=p*2;i>=p*2-p+2;i--)
		{
			if(m>=i)
				sum+=m-i+1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
