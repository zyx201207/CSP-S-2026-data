#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c==11 || c==12)
		{
			int tmp=d/((a[n]-a[1])/(n-1));
			cout<<n-tmp-1;
		}
		else
			cout<<n*(n-1)/2;
		cout<<"\n";
	}
	return 0;
}

