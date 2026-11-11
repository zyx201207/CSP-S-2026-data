#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;

int n,d,c,t,ans;
long long x[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n%2==1)
		{
			int m=0;
			for(int j=2;j<=(n+1)/2;j++)
			{
				if(x[n]-x[j]<=d) m++;
			}
			if(m>2) 
			{
				cout<<0<<endl;
				break;
			}
		}
	}
	return 0;
}
