#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD=INT_MAX;
const int MAXN=2e6;
int c,t,n;
ll d,x[MAXN+5];
int f[MAXN+5];

bool flagA;
ll diff;
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
int main()
{
	init();
	cin>>c>>t;
	while (t--)
	{
		flagA=1;
		cin>>n>>d;
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
		{
			cin>>x[i];
			if (i==2) diff=x[i]-x[i-1];
			if (i>=3&&x[i]-x[i-1]!=diff) flagA=0;
		}
		if (flagA)
		{
			int t=(d-diff*2)/diff*diff+diff*2;
			int t2=t*2/diff;
			cout<<n-t2+1<<endl;
		}
	}
	return 0;
}

